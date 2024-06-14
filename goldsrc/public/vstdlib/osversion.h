/*
 * This file is part of OGS Engine SDK
 * Copyright (C) 2024 BlackPhrase
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

#pragma once

#include "vstdlib.h"

/// OS types we know about
/// Must be in ascending capability order, we use this for min OS requirements
enum eOSType
{
	Unknown = -1,
	
	WinUnknown = 0,
	Win311,
	Win95,
	Win98,
	WinME,
	WinNT,
	Win2000,
	WinXP,
	Win2003,
	WinVista,
	Win7, // TODO: Windows7?
	Win2008,
	Win8,
	Win81,
	Win10,
	Win11,
	WinMax,
	
	Dreamcast,
	PlayStation2,
	Xbox,
	GameCube,
	GBA,
	
	Xbox360,
	
	LinuxUnknown = -203,
	Linux22 = -202,
	Linux24 = -201,
	Linux26 = -200,
	//LinuxMax = -103,
	
	MacOSUnknown = -102,
	MacOS104 = -101,
	MacOS105 = -100,
	MacOS1058 = -99,
	MacOS106 = -95,
	MacOS1063 = -94,
	MacOS107 = -90,
	//MacOSMax = -1,
	
	//Android,
	
	//XboxSeriesS,
	//XboxSeriesX,
	//PlayStation5,
	
	Max = WinMax + 11 // Win types + other ifdef'd types
};

VSTDLIB_INTERFACE const char *GetNameFromOSType(eOSType aeType);
//VSTDLIB_INTERFACE const char *GetOSDetailString(char *asOutBuf, int anOutBuf); // TODO: not present in gs
VSTDLIB_INTERFACE eOSType GetOSType();
//VSTDLIB_INTERFACE bool OSTypesAreCompatible(eOSType aeTypeDetected, eOSType aeTypeRequired); // TODO: not present in gs
//VSTDLIB_INTERFACE const char *GetPlatformName(bool *apIs64Bit); // TODO: not present in gs
VSTDLIB_INTERFACE eOSType GetOSTypeFromString(const char *asString);