/*
 * This file is part of OGS Engine SDK
 *
 * Copyright (C) 2023 BlackPhrase
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
/// @brief console/config variable wrapper/reference class

#pragma once

#include <next/CommonTypes.hpp>

interface IConVar;

class CConVarRef
{
public:
	CConVarRef(const char *asName, bool abIgnoreMissing = true); // TODO: false?
	CConVarRef(IConVar *apVar);
	
	// Setters
	
	void SetString(const char *asValue);
	void SetInt(int anValue);
	void SetFloat(float afValue);
	void SetBool(bool abValue);
	
	void SetValue(const char *asValue){SetString(asValue);}
	void SetValue(int anValue){SetInt(anValue);}
	void SetValue(float afValue){SetFloat(afValue);}
	void SetValue(bool abValue){SetBool(abValue);}
	
	// Getters
	
	const char *GetName() const;
	const char *GetDesc() const;
	
	const char *GetDefValue() const;
	
	const char *GetString() const;
	int GetInt() const;
	float GetFloat() const;
	bool GetBool() const; //{return GetInt() > 0;}
	
	// Checks
	
	bool IsValid() const;
	
	operator bool(){return IsValid();}
	
	bool HasFlags(int anFlags) const;
private:
	IConVar *mpVar{nullptr};
};