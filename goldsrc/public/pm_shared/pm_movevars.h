/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2018, 2020-2021, 2023 BlackPhrase
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
/// @brief move/physics variables

#pragma once

typedef struct movevars_s
{
	float gravity; ///< Gravity for map
	float stopspeed; ///< Deceleration when not moving
	float maxspeed; ///< Max allowed speed
	float spectatormaxspeed; ///< Same as above but for spectators
	float accelerate; ///< Acceleration factor
	float airaccelerate; ///< Acceleration factor for open air
	float wateraccelerate; ///< Acceleration factor for water
	float friction;
	float edgefriction; ///< Extra friction near dropofs
	float waterfriction; ///< Less in water
	float entgravity; ///< Custom entity gravity, usually equals to 1.0
	float bounce; ///< Wall bounce value, usually equals to 1.0
	float stepsize; ///< Length of a single step set by the sv_stepsize cvar
	float maxvelocity; ///< Max server velocity
	
	float zmax; ///< Max Z-buffer range (for renderer)
	float waveHeight; ///< Water wave height (for renderer)
	
	qboolean footsteps; ///< Are footsteps sounds enabled?
	
	char skyName[32]; ///< Name of the sky map
	
	// These two are probably used only by the client-side...?
	float rollangle; // = cvar_t cl_rollangle?
	float rollspeed; // = cvar_t cl_rollspeed?
	
	float skycolor_r; ///< Sky color, red channel
	float skycolor_g; ///< Sky color, green channel
	float skycolor_b; ///< Sky color, blue channel
	
	float skyvec_x; ///< Sky vector, X value
	float skyvec_y; ///< Sky vector, Y value
	float skyvec_z; ///< Sky vector, Z value
} movevars_t;

extern movevars_t movevars;