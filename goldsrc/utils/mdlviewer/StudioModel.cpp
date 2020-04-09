/*
 * This file is part of OGS Engine
 * Copyright (C) 2020 BlackPhrase
 *
 * OGS Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#include <cstdio>
#include <cmath>

#include <gl/gl.h>

#include "StudioModel.hpp"

void CStudioModel::Init(const char *asModelName)
{
	mpStudioHdr = LoadModel(asModelName);
	
	// Preload textures
	mpTextureHdr = mpStudioHdr;
	
	if(mpStudioHdr->numtextures == 0)
	{
		char sTextureName[256]{};
		
		strncpy(sTextureName, asModelName, sizeof(sTextureName) - 1);
		strcpy(&sTextureName[strlen(sTextureName) - 4], "T.mdl");
		
		mpTextureHdr = LoadModel(sTextureName);
	};
	
	// Preload animations
	if(mpStudioHdr->numseqgroups > 1)
	{
		for(int i = 1; i < mpStudioHdr->numseqgroups; ++i)
		{
			char sSeqGroupName[256]{};
			
			strncpy(sSeqGroupName, asModelName, sizeof(sSeqGroupName) - 1);
			sprintf(&sSeqGroupName[strlen(sSeqGroupName) - 4], "%02d.mdl", i);
			
			mpAnimHdr[i] = LoadDemandSequences(sSeqGroupName);
		};
	};
};

void CStudioModel::Draw()
{
	if(mpStudioHdr->numbodyparts == 0)
		return;
	
	glPushMatrix();
	
	glTranslatef(mvOrigin[0], mvOrigin[1], mvOrigin[2]);
	
	glRotatef(mvAngles[1], 0, 0, 1);
	glRotatef(mvAngles[0], 0, 1, 0);
	glRotatef(mvAngles[2], 1, 0, 0);
	
	//glShadeModel(GL_SMOOTH);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	
	SetupBones();
	
	SetupLighting();
	
	for(int i = 0; i < mpStudioHdr->numbodyparts; ++i)
	{
		SetupModel(i);
		DrawPoints();
	};
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	//glShadeModel(GL_FLAT);
	
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glPopMatrix();
};

void CStudioModel::AdvanceFrame(float afDeltaTime)
{
	auto pSeqDesc{reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->seqindex)) + mnSequence};
	
	if(afDeltaTime > 0.1f)
		afDeltaTime = 0.1f;
	
	mfFrame += pSeqDesc->fps * afDeltaTime;
	
	if(pSeqDesc->numframes <= 1)
		mfFrame = 0.0;
	else
	{
		auto nFrames{pSeqDesc->numframes - 1};
		mfFrame -= rint(mfFrame / nFrames) * nFrames;
	};
};

void CStudioModel::ExtractBBox(float *avMins, float *avMaxs)
{
	auto pSeqDesc{reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->seqindex))};
	
	// TODO: VectorCopy?
	
	avMins[0] = pSeqDesc[mnSequence].bbmin[0];
	avMins[1] = pSeqDesc[mnSequence].bbmin[1];
	avMins[2] = pSeqDesc[mnSequence].bbmin[2];
	
	avMaxs[0] = pSeqDesc[mnSequence].bbmax[0];
	avMaxs[1] = pSeqDesc[mnSequence].bbmax[1];
	avMaxs[2] = pSeqDesc[mnSequence].bbmax[2];
};

int CStudioModel::SetSequence(int anSequence)
{
	if(anSequence > mpStudioHdr->numseq)
		anSequence = 0;
	
	if(anSequence < 0)
		anSequence = mpStudioHdr->numseq - 1;
	
	mnSequence = anSequence;
	mfFrame = 0;
	
	return mnSequence;
};

void CStudioModel::GetSequenceInfo(void *apfFrameRate, float *apfGroundSpeed)
{
	auto pSeqDesc{reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->seqindex)) + mnSequence};
	
	if(pSeqDesc->numframes > 1)
	{
		auto a{pSeqDesc->fps / (pSeqDesc->numframes - 1)}; // TODO: freqrate?
		*apfFrameRate = 256.0f * a;
		*apfGroundSpeed = sqrt(pow(pSeqDesc->linearmovement[0], 2) + pow(pSeqDesc->linearmovement[1], 2) + pow(pSeqDesc->linearmovement[2], 2));
		*apfGroundSpeed *= a;
	}
	else
	{
		*apfFrameRate = 256.0f;
		*apfGroundSpeed = 0.0f;
	};
};

float CStudioModel::SetController(int anController, float afValue)
{
};

float CStudioModel::SetMouth(float afValue)
{
};

float CStudioModel::SetBlending(int anBlender, float afValue)
{
};

int CStudioModel::SetBodygroup(int anGroup, int anValue)
{
	if(anGroup > mpStudioHdr->numbodyparts)
		return -1;
	
	auto pBodyPart{reinterpret_cast<mstudiobodyparts_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->bodypartindex) + anGroup};
	
	int nCurrent{(mnBody / pBodyPart->base) % pBodyPart->nummodels};
	
	if(anValue >= pBodyPart->nummodels)
		return nCurrent;
	
	mnBody = (mnBody - (nCurrent * pBodyPart->base) + (anValue * pBodyPart->base));
	return anValue;
};

int CStudioModel::SetSkin(int anValue)
{
	if(anValue < mpStudioHdr->numskinfamilies)
		return mnSkin;
	
	mnSkin = anValue;
	return anValue;
};

studiohdr_t *CStudioModel::LoadModel(const char *asModelName)
{
	FILE *pFile{fopen(asModelName, "rb")};
	
	// Load the model
	if(pFile == nullptr)
	{
		printf("unable to open %s\n", asModelName);
		exit(1);
	};
	
	fseek(pFile, 0, SEEK_END);
	long nSize = ftell(pFile);
	
	fseek(pFile, 0, SEEK_SET);
	void *pBuffer = malloc(nSize);
	fread(pBuffer, nSize, 1, pFile);
	
	auto pIn = reinterpret_cast<byte*>(pBuffer);
	auto pHdr = reinterpret_cast<studiohdr_t*>(pIn);
	auto pTexture = reinterpret_cast<mstudiotexture_t*>(pIn + pHdr->textureindex);
	
	if(pHdr->textureindex != 0)
		for(int i = 0; i < pHdr->numtextures; ++i)
			UploadTexture(&pTexture[i], pIn + pTexture[i].index, pIn + pTexture[i].width * pTexture[i].height + pTexture[i].index);
	
	// TODO: free texture memory?
	
	fclose(pFile);
	return reinterpret_cast<studiohdr_t*>(pBuffer);
};

studioseqhdr_t *CStudioModel::LoadDemandSequences(const char *asModelName)
{
	FILE *pFile{fopen(asModelName, "rb")};
	
	// Load the model
	if(pFile == nullptr)
	{
		printf("unable to open %s\n", asModelName);
		exit(1);
	};
	
	fseek(pFile, 0, SEEK_END);
	long nSize = ftell(pFile);
	
	fseek(pFile, 0, SEEK_SET);
	void *pBuffer = malloc(nSize);
	fread(pBuffer, nSize, 1, pFile);
	
	fclose(pFile);
	return reinterpret_cast<studioseqhdr_t*>(pBuffer);
};

void CStudioModel::UploadTexture(mstudiotexture_t *apTexture, byte *apData, byte *apPalette)
{
	int nOutWidth{0}, nOutHeight{0};
	
	// Convert texture's width to power of 2
	for(nOutWidth = 1; nOutWidth < pTexture->width; nOutWidth <<= 1)
		;
	
	if(nOutWidth > 256)
		nOutWidth = 256;
	
	// Convert texture's height to power of 2
	for(nOutHeight = 1; nOutHeight < pTexture->height; nOutHeight <<= 1)
		;
	
	if(nOutHeight > 256)
		nOutHeight = 256;
	
	byte *pTexture, pOut;
	pTexture = pOut = reinterpret_cast<byte*>(malloc(nOutWidth * nOutHeight * 4));
	
	//pTexture->width = nOutWidth;
	//pTexture->height = nOutHeight;
	
	pTexture->index = gnTexNum;
	++gnTexNum;
	
	free(pTexture);
};

void CStudioModel::SetupModel(int anBodyPart)
{
};

void CStudioModel::SetupBones()
{
	static vec3_t vPos[MAXSTUDIOBONES];
	static vec4_t q[MAXSTUDIOBONES];
	
	static vec3_t vPos2[MAXSTUDIOBONES];
	static vec4_t q2[MAXSTUDIOBONES];
	
	static vec3_t vPos3[MAXSTUDIOBONES];
	static vec4_t q3[MAXSTUDIOBONES];
	
	static vec3_t vPos4[MAXSTUDIOBONES];
	static vec4_t q4[MAXSTUDIOBONES];
	
	float bonematrix[3][4];
	
	if(mnSequence >= mpStudioHdr->numseq)
		mnSequence = 0;
	
	auto pSeqDesc{reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->seqindex)) + mnSequence};
	
	mstudioanim_t *pAnim{GetAnim(pSeqDesc};
	
	CalcRotations(vPos, q, pSeqDesc, pAnim, mfFrame);
	
	if(pSeqDesc->numblends > 1)
	{
		pAnim += mpStudioHdr->numbones;
		
		CalcRotations(pos2, q2, pSeqDesc, pAnim, mfFrame);
		
		float s{mnBlending[0] / 255.0f};
		
		SlerpBones(q, pos, q2, pos2, s);
		
		if(pSeqDesc->numblends == 4)
		{
			pAnim += mpStudioHdr->numbones;
			CalcRotations(pos3, q3, pSeqDesc, pAnim, mfFrame);
			
			pAnim += mpStudioHdr->numbones;
			CalcRotations(pos4, q4, pSeqDesc, pAnim, mfFrame);
			
			s = mnBlending[0] / 255.0f;
			SlerpBones(q3, pos3, q4, pos4, s);
			
			s = mnBlending[1] / 255.0f;
			SlerpBones(q, pos, q3, pos3, s);
		};
	};
	
	auto pBones{reinterpret_cast<mstudiobone_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->boneindex))};
	
	for(int i = 0; i < mpStudioHdr->numbones; ++i)
	{
		QuaternionMatrix(q[i], bonematrix);
		
		bonematrix[0][3] = pos[i][0];
		bonematrix[1][3] = pos[i][1];
		bonematrix[2][3] = pos[i][2];
		
		if(pBones[i].parent == -1)
			memcpy(gvBoneTransform[i], bonematrix, sizeof(float) * 12);
		else
			R_ConcatTransforms(gvBoneTransform[pBones[i].parent], bonematrix, gvBoneTransform[i]);
	};
};

void CStudioModel::SetupLighting()
{
};

void CStudioModel::CalcBoneAdj()
{
auto pBoneCtrl{reinterpret_cast<mstudiobonecontroller_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->bonecontrollerindex))};
	
	int i{0};
	float fValue{0.0f};
	
	for(int j = 0; j < mpStudioHdr->numbonecontrollers; ++j)
	{
		i = pBoneCtrl[j].index;
		
		if(i <= 3)
		{
			// Check for 360% wrapping
			if(pBoneCtrl[j].type & STUDIO_RLOOP)
				fValue = mnController[i] * (360.0 / 256.0) + pBoneCtrl[j].start;
			else
			{
				fValue = mnController[i] / 255.0;
				
				if(fValue < 0.0f)
					fValue = 0.0f;
				
				if(fValue > 1.0f)
					fValue = 1.0f;
				
				fValue = (1.0f - fValue) * pBoneCtrl[j].start + fValue * pBoneCtrl[j].end;
			};
			
			//Con_DPrintf("%d %d %f : %f\n", mnController[j], mnPrevController[j], fValue, dadt);
		}
		else
		{
			fValue = mnMouth / 64.0f;
			
			if(fValue > 1.0f)
				fValue = 1.0f;
			
			fValue = (1.0f - fValue) * pBoneCtrl[j].start + fValue * pBoneCtrl[j].end;
			//Con_DPrintf("%d %f\n", mouthopen, fValue);
		};
		
		switch(pBoneCtrl[j].type & STUDIO_TYPES)
		{
		case STUDIO_XR:
		case STUDIO_YR:
		case STUDIO_ZR:
			mvAdj[j] = fValue * (Q_PI / 180.0f);
			break;
		case STUDIO_X:
		case STUDIO_Y:
		case STUDIO_Z:
			mvAdj[j] = fValue;
			break;
		};
	};
};

void CStudioModel::CalcBoneQuat(int anFrame, float s, mstudiobone_t *apBone, mstudioanim_t *apAnim, float *apQuat)
{
};

void CStudioModel::CalcBonePosition(int anFrame, float s, mstudiobone_t *apBone, mstudioanim_t *apAnim, float *avPos)
{
	int k{0};
	mstudioanimvalue_t *pAnimValue{nullptr};
	
	for(int j = 0; j < 3; ++j)
	{
		avPos[j] = apBone->value[j]; // default
		
		if(apAnim->offset[j] != 0)
		{
			pAnimValue = reinterpret_cast<mstudioanimvalue_t*>(reinterpret_cast<byte*>(apAnim + apAnim->offset[j]));
			
			k = anFrame;
			
			// Find span of values that includes the frame we want
			while(pAnimValue->num.total <= k)
			{
				k -= pAnimValue->num.total;
				pAnimValue += pAnimValue->num.valid + 1;
			};
			
			// If we're inside the span
			if(pAnimValue->num.valid > k)
			{
				// And there's more data in the span
				if(pAnimValue->num.valid > k + 1)
					avPos[j] += (pAnimValue[k + 1].value * (1.0f - s) + s * pAnimValue[k + 2].value) * apBone->scale[j];
				else
					avPos[j] += pAnimValue[k + 1].value * apBone->scale[j];
			}
			else
			{
				// Are we at the end of the repeating values section and there's another section with data?
				if(pAnimValue->num.total <= k + 1)
					avPos[j] += (pAnimValue[pAnimValue->num.valid].value * (1.0f - s) + s * pAnimValue[pAnimValue->num.valid + 2].value) * apBone->scale[j];
				else
					avPos[j] += pAnimValue[pAnimValue->num.valid].value * apBone->scale[j];
			};
		};
		
		if(apBone->bonecontroller[j] != -1)
			avPos[j] += mvAdj[apBone->bonecontroller[j]];
	};
};

void CStudioModel::CalcRotations(vec3_t *apPos, vec4_t *apQuat, mstudioseqdesc_t *apSeqDesc, mstudioanim_t *apAnim, float f)
{
	int nFrame = reinterpret_cast<int>(f);
	float s = f - nFrame;
	
	// Add in programatic controllers
	CalcBoneAdj();
	
	auto pBone{reinterpret_cast<mstudiobone_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->boneindex))};
	
	for(int i = 0; i < mpStudioHdr->numbones; ++i; ++pBone ++apAnim)
	{
		CalcBoneQuat(nFrame, s, pBone, apQuat);
		CalcBonePosition(nFrame, s, pBone, avPos);
	};
	
	if(apSeqDesc->motiontype & STUDIO_X)
		avPos[apSeqDesc->motionbone][0] = 0.0f;
	
	if(apSeqDesc->motiontype & STUDIO_Y)
		avPos[apSeqDesc->motionbone][1] = 0.0f;
	
	if(apSeqDesc->motiontype & STUDIO_Z)
		avPos[apSeqDesc->motionbone][2] = 0.0f;
};

void CStudioModel::SlerpBones(vec4_t q1[], vec3_t pos1[], vec4_t q2[], vec3_t pos2[], float s)
{
	if(s < 0.0f)
		s = 0.0f;
	else if(s > 1.0f)
		s = 1.0f;
	
	float s1{1.0f - s};
	
	vec4_t q3{};
	
	for(int i = 0; i < mpStudioHdr->numbones; ++i)
	{
		QuaternionSlerp(q1[i], q1[i], s, q3);
		
		q1[i][0] = q3[0];
		q1[i][1] = q3[1];
		q1[i][2] = q3[2];
		q1[i][3] = q3[3];
		
		pos1[i][0] = pos1[i][0] * s1 + pos2[i][0] * s;
		pos1[i][1] = pos1[i][1] * s1 + pos2[i][1] * s;
		pos1[i][2] = pos1[i][2] * s1 + pos2[i][2] * s;
	};
};

// TODO: was CStudioModel::TransformFinalVert?
void CStudioModel::Lighting(float *lv, int anBone, int anFlags, vec3_t avNormal)
{
	float fIllum = gfAmbientLight;
	
	if(anFlags & STUDIO_NF_FLATSHADE)
		fIllum += gfShadeLight * 0.8f;
	else
	{
		float fLightCos = DotProduct(avNormal, gvLight[anBone]); // -1 - colinear, 1 - opposite
		
		if(fLightCos > 1.0f)
			fLightCos = 1.0f;
		
		fIllum += gfShadeLight;
		
		float r = gfLambert;
		
		if(r <= 1.0f)
			r = 1.0f;
		
		fLightCos = (fLightCos + (r - 1.0f)) / r; // Do modified hemispherical lighting
		
		if(fLightCos > 0.0f)
			fIllum -= gfShadeLight * fLightCos;
		
		if(fIllum <= 0.0f)
			fIllum = 0.0f;
	};
	
	if(fIllum > 255.0f)
		fIllum = 255.0f;
	
	*lv = fIllum / 255.0f; // Light from 0.0 to 1.0
};

void CStudioModel::Chrome(int *apChrome, int anBone, vec3_t avNormal)
{
};

void CStudioModel::DrawPoints()
{
};

mstudioanim_t *CStudioModel::GetAnim(mstudioseqdesc_t *apSeqDesc) const
{
	auto pSeqGroup{reinterpret_cast<mstudioseqgroup_t*>(reinterpret_cast<byte*>(mpStudioHdr + mpStudioHdr->seqgroupindex)) + apSeqDesc->seqgroup};
	
	if(apSeqDesc->seqgroup == 0)
		return reinterpret_cast<mstudioanim_t*>(reinterpret_cast<byte*>(mpStudioHdr + pSeqGroup->data + apSeqDesc->animindex));
	
	return reinterpret_cast<mstudioanim_t*>(reinterpret_cast<byte*>(mpAnimHdr[apSeqDesc->seqgroup] + apSeqDesc->animindex));
};