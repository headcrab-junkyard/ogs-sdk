/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2018, 2020, 2022-2023 BlackPhrase
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
/// @brief player movement module definitions

#pragma once

#include <stdint.h>

//#include <archtypes.h>
#include <common/const.h>
#include "pm_info.h"
#include <common/pmtrace.h> // PM_PlayerTrace results
#include <common/usercmd.h>

// Must have room for all entities in the world
#define	MAX_PHYSENTS 600

#define MAX_MOVEENTS 64
#define MAX_CLIP_PLANES 5

#define PM_NORMAL 0x00000000
#define PM_STUDIO_IGNORE 0x00000001 ///< Skip studio models
#define PM_STUDIO_BOX 0x00000002 ///< Use boxes for non-complex studio models (even in traceline)
#define PM_GLASS_IGNORE 0x00000004 ///< Ignore entities with non-normal rendermode
#define PM_WORLD_ONLY 0x00000008 ///< Only trace against the world

// Values for flags parameter of PM_TraceLine
enum
{
	PM_TRACELINE_PHYSENTSONLY = 0,
	PM_TRACELINE_ANYVISIBLE
};

// Physical entity
typedef struct physent_s
{
	char name[32]; ///< Name of the model or "player"/"world" // TODO
	
	int player; // TODO
	
	vec3_t origin; ///< Model's origin in world coords
	
	struct model_s *model; ///< Only for bsp models
	struct model_s *studiomodel ///< SOLID_BBOX, but studio clip intersections // TODO
	
	vec3_t mins, maxs; ///< Only for non-bsp models
	
	int info; // For client or server to identify (index into edicts or cl_entities)
	
	vec3_t angles; // rotated entities need this info for hull testing to work
	
	int solid; ///< Triggers and func_door type water brushes are SOLID_NOT // TODO
	int skin; ///< BSP contents for such things as func_door water brushes // TODO
	int rendermode; ///< So we can ignore glass // TODO
	
	// Complex collision detection
	
	// Animation
	float frame; // TODO
	int sequence; // TODO
	byte controller[4]; // TODO
	byte blending[2]; // TODO
	
	int movetype; // TODO
	int takedamage; // TODO
	int blooddecal; // TODO
	int team; // TODO
	int classnumber; // TODO
	
	// For mods
	int iuser1; // TODO
	int iuser2; // TODO
	int iuser3; // TODO
	int iuser4; // TODO
	
	float fuser1; // TODO
	float fuser2; // TODO
	float fuser3; // TODO
	float fuser4; // TODO
	
	vec3_t vuser1; // TODO
	vec3_t vuser2; // TODO
	vec3_t vuser3; // TODO
	vec3_t vuser4; // TODO
} physent_t;

/*
typedef struct
{
	// player state
	qboolean dead;
} playermove_t;
*/

typedef struct hull_s hull_t;

typedef struct playermove_s
{
	int player_index; ///< So we don't try to run the PM_CheckStuck nudging too quickly // TODO
	
	qboolean server; ///< For debugging, are we running physics code on a server side?
	qboolean multiplayer; ///< 1 = multiplayer server // TODO
	
	float time; ///< = realtime on host, for reckoning duck timing // TODO
	float frametime; ///< Duration of this frame
	
	vec3_t forward, right, up; ///< Vectors for angles
	
	//int sequence;	// just for debugging prints // UNUSED

	// player state
	vec3_t origin; ///< Movement origin
	vec3_t angles; ///< Movement view angles
	vec3_t oldangles; ///< Angles before movement view angles were looked at // TODO
	vec3_t velocity; ///< Current movement direction
	vec3_t movedir; ///< For waterjumping, a forced forward velocity so we can fly over lip of ledge
	vec3_t basevelocity; ///< Velocity of the conveyor we are standing on // TODO
	
	// For ducking/dead
	vec3_t view_ofs; ///< Our eye position
	float flDuckTime; ///< Time we started to duck // TODO
	qboolean bInDuck; ///< In process of ducking or ducked already? // TODO
	
	// For walking/falling
	int flTimeStepSound; ///< Next time we can play a step sound // TODO
	int iStepLeft; // TODO
	
	float flFallVelocity; // TODO
	vec3_t punchangle; // TODO
	
	float flSwimTime; // TODO
	
	float flNextPrimaryAttack; // TODO
	
	int effects; ///< Muzzle flash and such // TODO
	
	int flags; ///< Currently set flags, FL_ONGROUND, FL_DUCKING, etc
	int usehull; ///< Currently used hull type, 0 = regular player hull, 1 = ducked player hull, 2 = point hull
	float gravity; ///< Our current gravity and friction // TODO
	float friction; // TODO
	int oldbuttons; ///< Buttons from last usercmd
	float waterjumptime; ///< Amout of time left in jumping out of water cycle
	qboolean dead; ///< Are we a dead player?
	int deadflag; // TODO
	int spectator; ///< Should we use spectator physics model?
	int movetype; ///< Our movement type, NOCLIP, WALK, FLY
	
	int onground;
	int waterlevel;
	int watertype;
	int oldwaterlevel;
	
	char sztexturename[256]; // TODO
	char chtexturetype; // TODO
	
	float maxspeed;
	float clientmaxspeed; ///< Player-specific maxspeed // TODO
	
	// For mods
	int iuser1; // TODO
	int iuser2; // TODO
	int iuser3; // TODO
	int iuser4; // TODO
	
	float fuser1; // TODO
	float fuser2; // TODO
	float fuser3; // TODO
	float fuser4; // TODO
	
	vec3_t vuser1; // TODO
	vec3_t vuser2; // TODO
	vec3_t vuser3; // TODO
	vec3_t vuser4; // TODO

	// world state
	int numphysent; ///< Number of entities to clip against
	physent_t physents[MAX_PHYSENTS];	// 0 should be the world
	
	int nummoveent; ///< Number of movement entities (ladders) // TODO
	physent_t moveents[MAX_MOVEENTS]; ///< Just a list of ladders // TODO
	
	/// All things being rendered, for tracing against things you don't actually collide with
	int numvisent; // TODO
	physent_t visents[MAX_PHYSENTS]; // TODO
	
	/// Input to run through physics
	usercmd_t cmd;

	/// Trace results for objects we collided with
	int numtouch;
	pmtrace_t touchindex[MAX_PHYSENTS]; // TODO: was int
	
	char physinfo[MAX_PHYSINFO_STRING]; ///< Physics info string // TODO
	
	struct movevars_s *movevars;
	
	vec3_t player_mins[MAX_HULLS];
	vec3_t player_maxs[MAX_HULLS];
	
	// Common functions
	
	const char *(*PM_Info_ValueForKey)(const char *s, const char *key);
	
	void (*PM_Particle)(float *origin, int color, float life, int zpos, int zvel);
	
	int (*PM_TestPlayerPosition)(float *pos, pmtrace_t *pTrace);
	
	void (*Con_NPrintf)(int idx, const char *fmt, ...);
	void (*Con_DPrintf)(const char *fmt, ...);
	void (*Con_Printf)(const char *fmt, ...);
	
	double (*Sys_FloatTime)();
	
	void (*PM_StuckTouch)(int hitent, pmtrace_t *pTraceResult);
	
	/// @param truecontents Filled in if this is non-null
	int (*PM_PointContents)(float *pos, int *truecontents);
	
	int (*PM_TruPointContents)(float *pos);
	int (*PM_HullPointContents)(hull_t *pHull, int num, float *pos);
	
	pmtrace_t (*PM_PlayerTrace)(float *start, float *end, int nTraceFlags, int ignore_pe);
	pmtrace_t *(*PM_TraceLine)(float *start, float *end, int flags, int usehull, int ignore_pe);
	
	int32_t (*RandomLong)(int32_t nLow, int32_t nHigh);
	float (*RandomFloat)(float fLow, float fHigh);
	
	int (*PM_GetModelType)(struct model_s *pModel);
	void (*PM_GetModelBounds)(struct model_s *model, float *mins, float *maxs);
	
	void *(*PM_HullForBsp)(physent_t *pEnt, float *pOffset);
	
	float (*PM_TraceModel)(physent_t *pEnt, float *start, float *end, trace_t *pTrace);
	
	int (*COM_FileSize)(const char *sFileName);
	byte *(*COM_LoadFile)(const char *sPath, int usehunk, int *pLength);
	void (*COM_FreeFile)(void *pBuffer);
	char *(*memfgets)(byte *pMemFile, int nFileSize, int *pFilePos, char *pBuffer, int nBufferSize);
	
	qboolean runfuncs; ///< Run functions for this frame?
	
	void (*PM_PlaySound)(int channel, const char *sample, float volume, float attentuation, int nFlags, int pitch);
	const char *(*PM_TraceTexture)(int ground, float *vstart, float *vend);
	void (*PM_PlaybackEventFull)(int flags, int clientindex, unsigned short eventindex, float delay,
		float *origin, float *angles,
		float fparam1, float fparam2,
		int iparam1, int param2,
		qboolean bparam1, qboolean bparam2);

	pmtrace_t (*PM_PlayerTraceEx)(float *start, float *end, int nTraceFlags, int (*pfnIgnore)(physent_t *pEntToIgnore));
	int (*PM_TestPlayerPositionEx)(float *pos, pmtrace_t *pTrace, int (*pfnIgnore)(physent_t *pEntToIgnore));
	pmtrace_t *(*PM_TraceLineEx)(float *start, float *end, int flags, int usehull, int (*pfnIgnore)(physent_t *pEntToIgnore));
} playermove_t;