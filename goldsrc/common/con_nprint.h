/*
 * This file is part of OGS Engine
 * Copyright (C) 2018, 2021 BlackPhrase
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

typedef struct con_nprint_s
{
	int index; ///< Row number
	float time_to_live; ///< Number of seconds before it disappears
	vec3_t color; ///< RGB color (0.0 -> 1.0 scale)
} con_nprint_t;

void Con_NPrintf(int index, const char *fmt, ...);
void Con_NXPrintf(con_nprint_t *info, const char *fmt, ...);