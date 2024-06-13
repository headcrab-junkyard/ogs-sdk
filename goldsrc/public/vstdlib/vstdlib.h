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

#include <tier0/platform.h>

/// DLL export stuff
#ifdef VSTDLIB_DLL_EXPORT
#	define VSTDLIB_INTERFACE DLL_EXPORT
#	define VSTDLIB_OVERLOAD DLL_GLOBAL_EXPORT
#	define VSTDLIB_CLASS DLL_CLASS_EXPORT
#	define VSTDLIB_GLOBAL DLL_GLOBAL_EXPORT
#else
#	define VSTDLIB_INTERFACE DLL_IMPORT
#	define VSTDLIB_OVERLOAD DLL_GLOBAL_IMPORT
#	define VSTDLIB_CLASS DLL_CLASS_IMPORT
#	define VSTDLIB_GLOBAL DLL_GLOBAL_IMPORT
#endif