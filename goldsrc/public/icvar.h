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
/// @brief DLL interface to ConVars/ConCommands

#pragma once

#include <next/CommonTypes.hpp>

#include "tier1/convar.h"
#include "tier1/interface.h"

#define VENGINE_CVAR_INTERFACE_VERSION "VEngineCvar002"

// NOTE: was class
interface ICvar // : public IBaseInterface // TODO?
{
public:
	/// Try to register a cvar
	virtual void RegisterConCommandBase(ConCommandBase *apVariable) = 0;
	
	/// If there is a "+<varname> <value>" on the command line, this returns the value
	/// Otherwise, it returns nullptr
	virtual const char *GetCommandLineValue(const char *asVariableName) = 0;
	
	/// Try to find the cvar pointer by name
	virtual ConVar *FindVar(const char *asVarName) = 0;
	virtual const ConVar *FindVar(const char *asVarName) const = 0;
	
	/// Get first ConCommandBase to allow iteration
	virtual ConCommandBase *GetCommands() = 0;
};

extern ICvar *cvar;