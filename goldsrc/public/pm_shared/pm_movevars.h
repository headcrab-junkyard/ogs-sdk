/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
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
/// @brief move variables

#pragma once

typedef struct movevars_s
{
	float gravity;
	float stopspeed;
	float maxspeed;
	float spectatormaxspeed;
	float accelerate;
	float airaccelerate;
	float wateraccelerate;
	float friction;
	float edgefriction;
	float waterfriction;
	float entgravity;
	float bounce;
	float stepsize;
	float maxvelocity;
	
	float zmax;
	float waveHeight;
	
	qboolean footsteps;
	
	char skyName[32];
	
	// These two are probably used only by the client-side...?
	float rollangle; // = cvar_t cl_rollangle
	float rollspeed; // = cvar_t cl_rollspeed
	
	float skycolor_r;
	float skycolor_g;
	float skycolor_b;
	
	float skyvec_x;
	float skyvec_y;
	float skyvec_z;
} movevars_t;

extern movevars_t movevars;