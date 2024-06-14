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
/// @brief interface to shared data repository for KeyValues (included in vgui_controls.lib)
/// Allows for central data storage point of KeyValues symbol table

#pragma once

#include "vstdlib.h"

#define INVALID_KEY_SYMBOL (-1)

/// Handle to a KeyValues key name symbol
using HKeySymbol = int;

class IKeyValuesSystem
{
public:
	/// Registers the size of the KeyValues in the specified instance
	/// so it can build a properly sized memory pool for the KeyValues objects
	/// The sizes will usually never differ but this is for versioning safety
	virtual void RegisterSizeofKeyValues(int anSize) = 0;
	
	/// Allocates/frees a KeyValues object from the shared mempool
	virtual void *AllocKeyValuesMemory(int anSize) = 0;
	virtual void FreeKeyValuesMemory(void *apMemory) = 0;
	
	/// Symbol table access (used for key names)
	virtual HKeySymbol GetSymbolForString(const char *asName, bool abCreate = true) = 0;
	virtual const char *GetStringForSymbol(HKeySymbol anSymbol) = 0;
	
	/// For debugging, adds KeyValues record into global list so we can track memory leaks
	virtual void AddKeyValuesToMemoryLeakList(void *apMemory, HKeySymbol anName) = 0;
	virtual void RemoveKeyValuesFromMemoryLeakList(void *apMemory) = 0;
};

VSTDLIB_INTERFACE IKeyValuesSystem *KeyValuesSystem();

//#define KEYVALUESSYSTEM_INTERFACE_VERSION "KeyValuesSystem002"