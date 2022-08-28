/*
 * This file is part of OGS Engine
 * Copyright (C) 2022 BlackPhrase
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

#include <cstdio>

#include "IRegistry.hpp"

#include <windows.h>

class CRegistry : public IRegistry
{
public:
    CRegistry();
    ~CRegistry();

    void SetString(const char *asKey, const char *asValue) override;
    const char *GetString(const char *asKey) const override;

    void SetInt(const char *asKey, int anValue) override;
    int GetInt(const char *asKey) const override;
    
    void SetBool(const char *asKey, bool abValue) override;
    bool GetBool(const char *asKey) const override;
private:
    HKEY mhKey{0};
};

CRegistry gRegistry;

IRegistry *GetRegistry()
{
    return &gRegistry;
};

char msValue[64]{};

// WORKS
CRegistry::CRegistry()
{
    auto sPath{"Software\\Valve\\Half-Life\\Settings"};
	
	printf("Trying to open a path...\n");
	
	auto nResult{RegOpenKeyEx(
		HKEY_CURRENT_USER,
        sPath,
		0,
		KEY_ALL_ACCESS,
		&mhKey)};
	
	if(nResult == ERROR_SUCCESS)
		printf("Path found\n");
	else
	{
		printf("Path not found, creating a new one...\n");
		RegCreateKeyEx(
			HKEY_CURRENT_USER,
			sPath,
			0,
			nullptr,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			nullptr,
			&mhKey,
			nullptr
		);
	};
};

// WORKS
CRegistry::~CRegistry()
{
	printf("Trying to close the path...\n");
    RegCloseKey(mhKey);
};

// ?
void CRegistry::SetString(const char *asKey, const char *asValue)
{
    RegSetValueEx(mhKey, asKey, 0, REG_SZ, reinterpret_cast<const BYTE*>(asValue), strlen(asValue) + 1);
};

// ?
const char *CRegistry::GetString(const char *asKey) const
{
	DWORD nLen{sizeof(msValue)};
	memset(msValue, 0, sizeof(msValue));
    RegQueryValueEx(mhKey, asKey, nullptr, nullptr, reinterpret_cast<LPBYTE>(msValue), &nLen);
	return msValue;
};

// WORKS
void CRegistry::SetInt(const char *asKey, int anValue)
{
    RegSetValueEx(mhKey, asKey, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&anValue), sizeof(anValue));
};

// WORKS
int CRegistry::GetInt(const char *asKey) const
{
	DWORD nLen{sizeof(msValue)};
	memset(msValue, 0, sizeof(msValue));
	RegQueryValueEx(mhKey, asKey, nullptr, nullptr, reinterpret_cast<LPBYTE>(msValue), &nLen);
	auto nValue{reinterpret_cast<LPDWORD>(&msValue)};
	return *nValue;
};

// ?
void CRegistry::SetBool(const char *asKey, bool abValue)
{
    SetInt(asKey, abValue ? 1 : 0);
};

// ?
bool CRegistry::GetBool(const char *asKey) const
{
    return GetInt(asKey) ? true : false;
};