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

#pragma once

#include "const.h"

extern vec3_t gvRight; ///< Needs to be set to viewer's right in order for chrome to work
extern float gfLambert; ///< Modifier for pseudo-hemispherical lighting

class CStudioModel
{
public:
	void Init(const char *asModelName);
	
	void Draw();
	
	void AdvanceFrame(float afDeltaTime);
	
	void ExtractBBox(float *avMins, float *avMaxs);
	
	int SetSequence(int anSequence);
	int GetSequence() const {return mnSequence;}
	
	void GetSequenceInfo(void *apfFrameRate, float *apfGroundSpeed);
	
	float SetController(int anController, float afValue);
	float SetMouth(float afValue);
	float SetBlending(int anBlender, float afValue);
	int SetBodygroup(int anGroup, int anValue);
	int SetSkin(int anValue);
private:
	studiohdr_t *LoadModel(const char *asModelName);
	studioseqhdr_t *LoadDemandSequences(const char *asModelName);
	
	void UploadTexture(mstudiotexture_t *apTexture, byte *apData, byte *apPalette);
	
	void SetupModel(int anBodyPart);
	void SetupBones();
	void SetupLighting();
	
	void CalcBoneAdj();
	void CalcBoneQuat(int anFrame, float s, mstudiobone_t *apBone, mstudioanim_t *apAnim, float *apQuat);
	void CalcBonePosition(int anFrame, float s, mstudiobone_t *apBone, mstudioanim_t *apAnim, float *avPos);
	void CalcRotations(vec3_t *apPos, vec4_t *apQuat, mstudioseqdesc_t *apSeqDesc, mstudioanim_t *apAnim, float f);
	
	void SlerpBones(vec4_t q1[], vec3_t pos1[], vec4_t q2[], vec3_t pos2[], float s);
	
	void Lighting(float *lv, int anBone, int anFlags, vec3_t avNormal);
	void Chrome(int *apChrome, int anBone, vec3_t avNormal);
	
	void DrawPoints();
	
	mstudioanim_t *GetAnim(mstudioseqdesc_t *apSeqDesc) const;
private:
	vec4_t mvAdj; // TODO: non-persistent, make static

	// Entity settings
	vec3_t mvOrigin;
	vec3_t mvAngles;
	
	float mfFrame{0.0f};
	
	int mnSequence{0}; ///< Sequence index
	int mnBody{0}; ///< Bodypart selection
	int mnSkin{0}; ///< Skin group selection
	
	byte mnController[4]; ///< Bone controllers
	byte mnBlending[2]; ///< Animation blending
	byte mnMouth; ///< Mouth position
	
	// Internal data
	studiohdr_t *mpStudioHdr{nullptr};
	mstudiomodel_t *mpModel{nullptr};
	
	studiohdr_t *mpTextureHdr{nullptr};
	studioseqhdr_t *mpAnimHdr[32]{};
};