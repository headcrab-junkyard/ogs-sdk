/*
 * This file is part of OGS Engine
 * Copyright (C) 2018, 2022 BlackPhrase
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

/// DLL State Flags
enum
{
	DLL_INACTIVE = 0, ///< No DLL
	DLL_ACTIVE, ///< DLL is running
	DLL_PAUSED, ///< DLL is paused
	DLL_CLOSE, ///< Closing down DLL
	DLL_TRANS ///< Level transition
};

/// DLL Pause reasons
enum
{
	DLL_NORMAL = 0, ///< User hit ESC or something
	DLL_QUIT = 4, ///< Quit now
	DLL_RESTART = 6 ///< Switch to launcher for Linux, does a quit but returns 1
};

/// DLL Substate info (not relevant)
#define ENG_NORMAL (1 << 0)