/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2023 BlackPhrase
 *
 * OGSNext Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGSNext Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGSNext Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @brief shader interface

#pragma once

#include <next/CommonTypes.hpp>

/// Info about each shader parameter
struct SShaderParamInfo
{
	const char *msName{""};
	const char *msHelp{""};
	const char *msDefaultValue{""};
	
	ShaderParamType_t meType{};
	
	enum class Flags : int
	{
		NotEditable = 0x1
	};
	
	int mnFlags{0};
};

interface IShader
{
	/// @return the shader name
	virtual const char *GetName() const = 0;
	
	///
	virtual int GetFlags() const = 0;
	
	///
	virtual const SShaderParamInfo &GetParamInfo(int anIndex) const = 0;
	
	///
	virtual void SetUniform4f(const char *asName, float *avValues) = 0; // TODO: SetVar4f?
};