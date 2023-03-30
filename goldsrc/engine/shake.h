/*
 * This file is part of OGS Engine SDK
 * Copyright (C) 2018, 2023 BlackPhrase
 *
 * OGS Engine SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine SDK. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @brief screen/view effects

#pragma once

#include <common/const.h>

/// Screen shake message
extern int gmsgShake;

/// Screen fade (in/out) message
extern int gmsgFade;

// Fade flags
enum
{
	FFADE_IN = 0x0000, ///< Just here so we don't pass 0 into the function
	FFADE_OUT = 0x0001, ///< Fade out (not in)
	FFADE_MODULATE 0x0002, ///< Modulate (don't blend)
	FFADE_STAYOUT = 0x0004, ///< Ignore the duration, stay faded out until new ScreenFade message received
	FFADE_LONGFADE = 0x0008 ///< Used to indicate the fade can be longer than 16 seconds
};

/// This structure is sent over the net to describe a screen shake event
typedef struct
{
	unsigned short amplitude; ///< Amount of shake
	unsigned short duration; ///< Duration in seconds
	unsigned short frequence; ///< Noise frequency (low frequency is a jerk, high frequency is a rumble)
} ScreenShake;

/// THis structure is sent over the net to describe a screen fade event
typedef struct
{
	unsigned short duration; ///< Duration in seconds
	unsigned short holdTime; ///< Duration in seconds until reset (fade & hold)
	short fadeFlags; ///< Fade flags (see above)
	byte r, g, b, a; ///< Fade color (with alpha)
} ScreenFade;

void V_ApplyShake(float *origin, float *angles, float factor);
void V_CalcShake();

int V_ScreenShake(const char *asName, int anSize, void *apBuffer);
int V_ScreenFade(const char *asName, int anSize, void *apBuffer);