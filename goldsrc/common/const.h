/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-2001 Id Software, Inc.
 * Copyright (C) 2018, 2020-2021 BlackPhrase
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

#include "mathlib.h"

#define MAX_QPATH 64

// edict->flags
#define	FL_FLY					1
#define	FL_SWIM					2
//#define	FL_GLIMPSE				4
#define	FL_CONVEYOR				4
#define	FL_CLIENT				8
#define	FL_INWATER				16
#define	FL_MONSTER				32
#define	FL_GODMODE				64
#define	FL_NOTARGET				128
#define	FL_ITEM					256
#define	FL_ONGROUND				512
#define	FL_PARTIALGROUND		1024	// not all corners are valid
#define	FL_WATERJUMP			2048	// player jumping out of water
#define FL_FROZEN (1 << 12)
#define FL_FAKECLIENT (1 << 13)
//#define	FL_JUMPRELEASED			4096	// for jump debouncing

#define FL_IMMUNE_WATER	131072
#define	FL_IMMUNE_SLIME	262144
#define FL_IMMUNE_LAVA	524288

#define FL_KILLME (1 << 30)

// edict->movetype values
#define	MOVETYPE_NONE			0		// never moves
#define	MOVETYPE_ANGLENOCLIP	1
#define	MOVETYPE_ANGLECLIP		2
#define	MOVETYPE_WALK			3		// gravity
#define	MOVETYPE_STEP			4		// gravity, special edge handling
#define	MOVETYPE_FLY			5
#define	MOVETYPE_TOSS			6		// gravity
#define	MOVETYPE_PUSH			7		// no clip to world, push and crush
#define	MOVETYPE_NOCLIP			8
#define	MOVETYPE_FLYMISSILE		9		// extra size to monsters
#define	MOVETYPE_BOUNCE			10
#define MOVETYPE_BOUNCEMISSILE	11		// bounce w/o gravity
#define MOVETYPE_FOLLOW			12		// track movement of aiment

// edict->solid values
enum
{
	SOLID_NOT = 0,	// no interaction with other objects
	SOLID_TRIGGER,	// touch on edge, but not blocking
	SOLID_BBOX,		// touch on edge, block
	SOLID_SLIDEBOX,	// touch on edge, but not an onground
	SOLID_BSP		// bsp clip, touch on edge, block
};

// edict->deadflag values
enum
{
	DEAD_NO = 0,
	DEAD_DYING,
	DEAD_DEAD,
	DEAD_RESPAWNABLE
};

enum
{
	DAMAGE_NO = 0,
	DAMAGE_YES,
	DAMAGE_AIM
};

// entity effects

#define	EF_BRIGHTFIELD			1
#define	EF_MUZZLEFLASH 			2
#define	EF_BRIGHTLIGHT 			4
#define	EF_DIMLIGHT 			8
#define EF_INVLIGHT			16
#define EF_NOINTERP			32
#define EF_LIGHT				64
#define EF_NODRAW				128

//
// temp entity events
//
enum
{
//#define	TE_SPIKE			0
//#define	TE_SUPERSPIKE		1
	TE_BEAMPOINTS = 0,
	TE_BEAMENTPOINT,
	TE_GUNSHOT,
	TE_EXPLOSION,
	TE_TAREXPLOSION,
	TE_SMOKE = 5,
	TE_TRACER,
	TE_LIGHTNING,
	TE_BEAMENTS,
	TE_SPARKS,
//#define	TE_LIGHTNING1		5
//#define	TE_LIGHTNING2		6
//#define	TE_WIZSPIKE			7
//#define	TE_KNIGHTSPIKE		8
//#define	TE_LIGHTNING3		9
	TE_LAVASPLASH = 10,
	TE_TELEPORT,
	TE_EXPLOSION2,
	TE_BSPDECAL,
	TE_IMPLOSION,
	TE_SPRITETRAIL = 15,

// PGM 01/21/97 
	TE_BEAM = 16, // obsolete
// PGM 01/21/97

	TE_BEAMSPRITE,
	TE_BEAMTORUS,
	TE_BEAMDISK,
	TE_BEAMCYLINDER,
	TE_BEAMFOLLOW,
	
	TE_GLOWSPRITE,
	
	TE_BEAMRING,
	
	TE_STREAK_SPLASH,
	
	TE_BEAMHOSE,
	
	TE_DLIGHT,
	TE_ELIGHT,
	
	TE_TEXTMESSAGE,

	TE_LINE,
	TE_BOX = 31,
	
	TE_KILLBEAM = 99,
	TE_LARGEFUNNEL,
	TE_BLOODSTREAM,
	TE_SHOWLINE,
	TE_BLOOD,
	TE_DECAL,
	TE_FIZZ,
	TE_MODEL,
	TE_EXPLODEMODEL,
	TE_BREAKMODEL,
	TE_GUNSHOTDECAL,
	TE_SPRITE_SPRAY,
	TE_ARMOR_RICOCHET,
	TE_PLAYERDECAL,
	TE_BUBBLES,
	TE_BUBBLETRAIL,
	TE_BLOODSPRITE,
	TE_WORLDDECAL,
	TE_WORLDDECALHIGH,
	TE_DECALHIGH,
	TE_PROJECTILE,
	TE_SPRAY,
	TE_PLAYERSPRITES,
	TE_PARTICLEBURST,
	TE_FIREFIELD,
	TE_PLAYERATTACHMENT,
	TE_KILLPLAYERATTACHMENTS,
	TE_MULTIGUNSHOT,
	TE_USERTRACER = 127
};

enum
{
	MSG_BROADCAST = 0,	// unreliable to all
	MSG_ONE,			// reliable to one (msg_entity)
	MSG_ALL,			// reliable to all
	MSG_INIT			// write to the init string
};

#define CONTENTS_EMPTY  -1
#define CONTENTS_SOLID  -2
#define	CONTENTS_WATER	-3
#define CONTENTS_SLIME	-4
#define CONTENTS_LAVA	-5
#define CONTENTS_SKY    -6
#define CONTENTS_LADDER -16

// TODO: refactor this!
#define CONTENT_EMPTY  -1
#define CONTENT_SOLID  -2
#define	CONTENT_WATER	-3
#define CONTENT_SLIME	-4
#define CONTENT_LAVA	-5
#define CONTENT_SKY    -6

// channels
enum
{
	CHAN_AUTO = 0,
	CHAN_WEAPON,
	CHAN_VOICE,
	CHAN_ITEM,
	CHAN_BODY
};

// attenuation values
enum
{
	ATTN_NONE = 0,
	ATTN_NORM,
	ATTN_IDLE,
	ATTN_STATIC
};

#define PITCH_NORM 100

enum
{
	kRenderNormal,
	//kRenderTransColor,
};

enum
{
	kRenderFxNone = 0
};

enum
{
	HULL_PLAYER = 0, ///< regular player hull
	HULL_DUCKED, ///< ducked player hull
	HULL_POINT, ///< point hull
	HULL_LARGE, // TODO: ????????
	
	MAX_HULLS
};

typedef unsigned int uint;
typedef unsigned int func_t;
typedef unsigned int string_t;

#if !defined BYTE_DEFINED
typedef unsigned char byte;
#define BYTE_DEFINED 1
//#define _DEF_BYTE_
#endif

#undef true
#undef false

#ifdef __cplusplus
typedef int qboolean;
#else
typedef enum {false, true} qboolean;
#endif

typedef struct
{
	byte r, g, b;
} color24;

typedef struct link_s
{
	struct link_s	*prev, *next;
} link_t;

typedef struct
{
	vec3_t	normal;
	float	dist;
} plane_t;

typedef struct edict_s edict_t;

typedef struct
{
	qboolean	allsolid;	// if true, plane is not valid
	qboolean	startsolid;	// if true, the initial point was in a solid area
	qboolean	inopen, inwater;
	float	fraction;		// time completed, 1.0 = didn't hit anything
	vec3_t	endpos;			// final position
	plane_t	plane;			// surface normal at impact
	edict_t	*ent;			// entity the surface is on
} trace_t;