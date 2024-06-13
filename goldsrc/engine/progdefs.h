/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2018-2022 BlackPhrase
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

#include <common/const.h>

typedef struct
{
	float time;
	float frametime;
	float force_retouch;	// force all entities to touch triggers
							// next frame.  this is needed because
							// non-moving things don't normally scan
							// for triggers, and when a trigger is
							// created (like a teleport trigger), it
							// needs to catch everything.
							// decremented each frame, so set to 2
							// to guarantee everything is touched
	string_t	mapname;
	string_t	startspot;
	float	deathmatch;
	float	coop;
	float	teamplay;
	float	serverflags; // propagated from level to level, used to keep track of completed episodes
	
	//float	total_secrets;
	//float	total_monsters;
	
	float	found_secrets; // number of secrets found
	//float	killed_monsters; // number of monsters killed
	
	// spawnparms are used to encode information about clients across server level changes
/*
	float	parm1;
	float	parm2;
	float	parm3;
	float	parm4;
	float	parm5;
	float	parm6;
	float	parm7;
	float	parm8;
	float	parm9;
	float	parm10;
	float	parm11;
	float	parm12;
	float	parm13;
	float	parm14;
	float	parm15;
	float	parm16;
*/
	
	// set by makevectors()
	vec3_t	v_forward;
	vec3_t	v_up;
	vec3_t	v_right;
	
	// set by traceline / tracebox
	float	trace_allsolid;
	float	trace_startsolid;
	float	trace_fraction;
	vec3_t	trace_endpos;
	vec3_t	trace_plane_normal;
	float	trace_plane_dist;
	int	trace_ent;
	float	trace_inopen;
	float	trace_inwater;
	
	int	msg_entity; // destination of single entity writes
	
	int maxClients; // TODO
	int maxEntities; // TODO
	
	const char *pStringBase; // TODO
	
	//string_t	null;
} globalvars_t;

//
// system fields (*** = do not set in prog code, maintained by C code)
//
typedef struct entvars_s
{
	string_t classname; ///< Spawn function
	string_t globalname; // TODO: unused
	
	vec3_t origin; // ***
	vec3_t oldorigin; // ***
	
	vec3_t velocity;
	vec3_t basevelocity;
	vec3_t clbasevelocity; ///< Base velocity that was passed in to server physics code so client can predict conveyors correctly. Server zeroes it, so we need to store it here // TODO: unused
	
	vec3_t movedir; ///< Mostly for doors, but also used for waterjump
	
	vec3_t angles; ///< Model angles
	vec3_t avelocity; ///< Angle velocity (in degrees per sec)
	
	vec3_t punchangle; ///< Auto-decaying view angle adjustment // TODO: unused?
	vec3_t v_angle; ///< Viewing/targeting angle for players
	
	// For parametric entities
	vec3_t endpos; // TODO: unused
	vec3_t startpos; // TODO: unused
	
	float impacttime; // TODO: unused
	float starttime; // TODO: unused
	
	int fixangle; ///< 0 - nothing, 1 - force view angles, 2 - add avelocity
	
	float idealpitch;
	float pitch_speed;
	
	float ideal_yaw;
	float yaw_speed;
	
	int modelindex; ///< *** model index in the precached list
	string_t model;
	
	int viewmodel; ///< Player's view model // TODO: unused?
	int weaponmodel; ///< World model (what other players will see) // TODO: unused?
	
	vec3_t absmin; ///< *** origin + mins / maxs (bounding box min translated to world coords)
	vec3_t absmax; ///< Bounding box max translated to world coords
	vec3_t mins; ///< Bounding box extents relative to origin (local bounding box min)
	vec3_t maxs; ///< Local bounding box max
	vec3_t size; ///< maxs - mins
	
	float ltime; ///< Local time for entity
	float nextthink;
	
	int movetype;
	int solid;
	
	int skin;
	int body; ///< Selected sub-model for studio models // TODO: unused
	int effects; // TODO: unused?
	
	float gravity; ///< % of "normal" gravity
	float friction; ///< Inverse elasticity value of MOVETYPE_BOUNCE // TODO: unused
	
	int light_level;
	
	int sequence; ///< Animation sequence // TODO: unused
	int gaitsequence; ///< Movement animation sequence for player (0 = none) // TODO: unused
	
	float frame; ///< % playback position in animation sequences (0-255)
	
	float animtime; ///< World time when frame was set // TODO: unused
	float framerate; ///< Animation playback rate (from -8x to 8x) // TODO: unused
	
	byte controller[4]; ///< Bone controller settings (0-255 for each) // TODO: unused
	byte blending[2]; ///< Blending amount between sub-sequences (0-255) // TODO: unused
	
	float scale; ///< Sprite rendering scale (0-255) // TODO: unused?
	
	int rendermode; // TODO: unused?
	float renderamt; // TODO: unused?
	vec3_t rendercolor; // TODO: unused?
	int renderfx; // TODO: unused?
	
	// stats
	float health;
	float frags; // TODO: unused?
	int weapons; ///< One of the IT_SHOTGUN, etc flags (bit mask for available items/weapons) // TODO: unused?
	float takedamage;
	
	int deadflag; // TODO: unused?
	vec3_t view_ofs; ///< Add to origin to get eye point
	
	int button;
	//int button0; // fire
	//int button1; // use
	//int button2; // jump
	int impulse; ///< For things like weapon changes, flashlight toggling, cheats and such
	
	edict_t *chain; ///< Entity pointer when linked into a list
	edict_t *dmg_inflictor; // TODO: unused?
	edict_t *enemy; // TODO: unused?
	edict_t	*aiment; ///< Entity pointer used when move type is set to MOVETYPE_FOLLOW, points to an entity this entity should follow
	edict_t *owner; ///< Who launched a missile // TODO: unused?
	edict_t	*groundentity;
	
	int spawnflags; // TODO: unused?
	int flags;
	
	int colormap; ///< Low byte - topcolor, high byte - bottomcolor
	int team;
	
	float max_health; ///< Players maximum health is stored here // TODO: unused?
	float teleport_time; ///< Don't back up
	
	float armortype; ///< Save this fraction of incoming damage // TODO: unused?
	float armorvalue; // TODO: unused?
	
	int waterlevel; ///< 0 = not in, 1 = feet, 2 = wast, 3 = eyes
	int watertype; ///< A contents value
	
	string_t target; // TODO: unused?
	string_t targetname; // TODO: unused?
	string_t netname; // TODO: unused?
	string_t message; ///< Trigger messages // TODO: unused?
	
	// damage is accumulated through a frame. and sent as one single
	// message, so the super shotgun doesn't generate huge messages
	float dmg_take; // TODO: unused?
	float dmg_save; // TODO: unused?
	float dmg; // TODO: unused?
	float dmgtime; // TODO: unused?
	
	/// Contains names of wavs to play
	string_t noise; // TODO: unused?
	string_t noise1; // TODO: unused?
	string_t noise2; // TODO: unused?
	string_t noise3; // TODO: unused?
	
	float speed;
	
	float air_finished; // TODO: unused?
	float pain_finished; // TODO: unused?
	float radsuit_finished; // TODO: unused?
	
	edict_t *pContainingEntity; // TODO: unused
	
	int playerclass; // TODO: unused
	float maxspeed; // TODO: unused
	
	float fov; // TODO: unused
	int weaponanim; // TODO: unused
	
	int pushmsec; // TODO: unused
	
	int bInDuck; // TODO: unused
	int flTimeStepSound; // TODO: unused
	int flSwimTime; // TODO: unused
	int flDuckTime; // TODO: unused
	int iStepLeft; // TODO: unused
	float flFallVelocity; // TODO: unused
	
	int gamestate; // TODO: unused
	
	int oldbuttons; // TODO: unused
	
	int groupinfo; // TODO: unused
	
	// For mods
	int iuser1; // TODO: unused
	int iuser2; // TODO: unused
	int iuser3; // TODO: unused
	int iuser4; // TODO: unused
	float fuser1; // TODO: unused
	float fuser2; // TODO: unused
	float fuser3; // TODO: unused
	float fuser4; // TODO: unused
	vec3_t vuser1; // TODO: unused
	vec3_t vuser2; // TODO: unused
	vec3_t vuser3; // TODO: unused
	vec3_t vuser4; // TODO: unused
	edict_t *euser1; // TODO: unused
	edict_t *euser2; // TODO: unused
	edict_t *euser3; // TODO: unused
	edict_t *euser4; // TODO: unused
	
	///////////////////////////////////
	
	//float	weaponframe;
	
	//float	currentammo;
	
	//float	ammo_shells;
	//float	ammo_nails;
	//float	ammo_rockets;
	//float	ammo_cells;
	
	//float	items; // bit flags
	//float	items2; // TODO: q2
	
	//int	goalentity; // a movetarget or an enemy 
	
	//float	sounds; // either a cd track number or sound number
	
	//float	drawPercent; // TODO: q2
	
	//float	mass; // TODO: q2
} entvars_t;