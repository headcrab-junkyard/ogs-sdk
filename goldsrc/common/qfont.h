/*
 * This file is part of OGS Engine
 * Copyright (C) 2018, 2022, 2024 BlackPhrase
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
/// @brief font stuff

#pragma once

#include "const.h"

#define NUM_GLYPHS 256

typedef struct
{
	short startoffset;
	short charwidth;
} charinfo;

typedef struct qfont_s
{
	int width;
	int height;
	
	int rowcount;
	int rowheight;
	
	charinfo fontinfo[NUM_GLYPHS];
	
	byte data[4];
} qfont_t;