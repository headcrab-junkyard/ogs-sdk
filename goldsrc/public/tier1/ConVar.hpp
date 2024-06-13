/*
 * This file is part of OGS Engine SDK
 *
 * Copyright (C) 2019-2023 BlackPhrase
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
/// @brief console/config variable inteface implementation

#pragma once

//#include <common/cvardef.h>

#include "IConVar.hpp"

using cvar_t = struct cvar_s;

class CConVar : public IConVar
{
public:
	CConVar(const char *asName, const char *asDefValue, int anFlags = 0, const char *asDesc = "<no desc>");
	CConVar(cvar_t *apData, const char *asDesc = "");
	//virtual ~CConVar() = default;
	
	void Reset() override; // TODO: Revert? ResetValue?
	
	// Setters
	
	void SetChangeValueListener(IConVarValueListener *apListener) override;
	
	void SetString(const char *asValue) override;
	void SetInt(int anValue) override;
	void SetFloat(float afValue) override;
	void SetBool(bool abValue) override;
	
	void SetValue(const char *asValue){SetString(asValue);}
	void SetValue(int anValue){SetInt(anValue);}
	void SetValue(float afValue){SetFloat(afValue);}
	void SetValue(bool abValue){SetBool(abValue);}
	
	// Getters
	
	const char *GetName() const override;
	const char *GetDesc() const override;
	
	const char *GetDefValue() const override;
	
	const char *GetString() const override;
	int GetInt() const override;
	float GetFloat() const override;
	bool GetBool() const override; //{return GetInt() > 0;}
	
	// Flags
	
	//void SetFlags(int anFlags) override;
	//void AddFlags(int anFlags) override;
	bool HasFlags(int anFlags) const override;
	//int GetFlags() const override;
private:
	cvar_t *mpData{nullptr};
	IConVarValueListener *mpValueChangeListener{nullptr};
	const char *msDefValue{""};
	const char *msDesc{""};
};