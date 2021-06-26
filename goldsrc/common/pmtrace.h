/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2018, 2020 BlackPhrase
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

typedef struct
{
	vec3_t	normal;
	float	dist;
} pmplane_t;

typedef struct pmtrace_s
{
	qboolean allsolid; ///< If true, plane is not valid
	qboolean startsolid; ///< If true, the initial point was in a solid area
	qboolean inopen, inwater; ///< End point is in empty space or in water
	
	float fraction; ///< Time completed, 1.0 = didn't hit anything
	vec3_t endpos; ///< Final position
	pmplane_t plane; ///< Surface normal at impact
	int ent; ///< Entity the surface is on (entity at impact)
	
	vec3_t deltavelocity; ///< Change in player's velocity caused by impact // TODO: put to use
	int hitgroup; ///< Only run on server // TODO: put to use
} pmtrace_t;