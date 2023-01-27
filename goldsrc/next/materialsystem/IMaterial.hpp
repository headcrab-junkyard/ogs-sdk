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
/// @brief material interface

#pragma once

#include <next/CommonTypes.hpp>

interface IShader;
interface ITexture;

interface IMaterial
{
	/// @return name of the material
	virtual const char *GetName() const = 0;
	
	/// Material types
	enum class Type : int
	{
		None = 0,
		
		Diffuse,
		DiffuseAlpha,
		DiffuseAdditive,
		DiffuseNormalMap,
		DiffuseSpecular,
		
		SizeOf
	};
	
	/// @return type of the material
	virtual Type GetType() const = 0;
	
	///
	virtual void SetShader(IShader::Type aeType, uint anNum, IShader *apShader) = 0;
	
	///
	virtual IShader *GetShader(IShader::Type aeType, uint anNum) const = 0;
	
	/// Sets the specified material texture to the specified texture
	// TODO: eMaterialTexture -> string?
	virtual void SetTexture(eMaterialTexture aeType, ITexture *apTexture) = 0;
	
	///
	// TODO: eMaterialTexture -> string?
	virtual ITexture *GetTexture(eMaterialTexture aeType) const = 0;
};