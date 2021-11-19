/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-2001 Id Software, Inc.
 * Copyright (C) 2018-2021 BlackPhrase
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

#pragma once

#define	FCVAR_ARCHIVE	(1 << 0)	///< set to cause it to be saved to vars.rc
#define	FCVAR_USERINFO	(1 << 1)	///< added to userinfo when changed
#define	FCVAR_SERVER	(1 << 2)	///< notifies players when changed

#define FCVAR_EXTDLL (1 << 3) ///< Defined by external DLL
#define FCVAR_CLIENTDLL (1 << 4) ///< Defined by the client DLL

#define FCVAR_PROTECTED (1 << 5)
#define FCVAR_SPONLY (1 << 6)
#define FCVAR_PRINTABLEONLY (1 << 7)
#define FCVAR_UNLOGGED (1 << 8)

//#define	FCVAR_SERVERINFO	4	///< added to serverinfo when changed
//#define	FCVAR_NOSET		8	///< don't allow change from console at all,
							/// but can be set from the command line
//#define	FCVAR_LATCH		16	///< save changes until server restart

// nothing outside the Cvar_*() functions should modify these fields!
typedef struct cvar_s
{
	const char	*name;
	/*const*/ char	*string;
	int			flags;
	//qboolean archive;		// set to true to cause it to be saved to vars.rc
	//qboolean server;		// notifies players when changed // TODO: qboolean info in QW (either userinfo or serverinfo)
	float	value;
	struct cvar_s *next;
} cvar_t;