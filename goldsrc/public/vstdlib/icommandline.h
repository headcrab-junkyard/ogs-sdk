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
/// @brief Interface to engine command line

#pragma once

#include <tier0/platform.h>

//abstract_class
struct ICommandLine
{
	///
	virtual void CreateCmdLine(const char *asLine) = 0;
	
	///
	virtual void CreateCmdLine(int argc, char **argv) = 0;
	
	///
	virtual const char *GetCmdLine() const = 0;
	
	/// Check whether a particular parameter exists
	virtual const char *CheckParm(const char *asParm, const char **apValue = 0) const = 0;
	
	///
	virtual void RemoveParm(const char *asParm) = 0;
	
	///
	virtual void AppendParm(const char *asParm, const char *asValues) = 0;
	
	/// @return the arguent after the one specified or the default if not found
	virtual const char *ParmValue(const char *asParm, const char *asDefaultValue = 0) const = 0;
	
	///
	virtual int ParmValue(const char *asParm, int anDefaultValue) const = 0;
	
	///
	virtual float ParmValue(const char *asParm, float afDefaultValue) const = 0;
	
	/// Gets at particular parameters
	virtual int ParmCount() const = 0;
	
	/// @return 0 if not found
	virtual int FindParm(const char *asParm) const = 0;
	
	///
	virtual const char *GetParm(int anIndex) const = 0;
};

/// Gets a singleton to the commandline interface
PLATFORM_INTERFACE ICommandLine *CommandLine();