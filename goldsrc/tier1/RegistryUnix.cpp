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

#include "IRegistry.hpp"

class CRegistryUnix : public IRegistry
{
public:
    CRegistryUnix();
    ~CRegistryUnix();

    void SetString(const char *asKey, const char *asValue) override;
    const char *GetString(const char *asKey) const override;

    void SetInt(const char *asKey, int anValue) override;
    int GetInt(const char *asKey) const override;

    void SetBool(const char *asKey, bool abValue) override;
    bool GetBool(const char *asKey) const override;
};

CRegistryUnix gRegistry;

IRegistry *GetRegistry()
{
    return &gRegistry;
};

CRegistryUnix::CRegistryUnix()
{

};

CRegistryUnix::~CRegistryUnix()
{

};

void CRegistryUnix::SetString(const char *asKey, const char *asValue)
{

};

const char *CRegistryUnix::GetString(const char *asKey) const
{
    return "";
};

void CRegistryUnix::SetInt(const char *asKey, int anValue)
{

};

int CRegistryUnix::GetInt(const char *asKey) const
{
    return 0;
};

void CRegistryUnix::SetBool(const char *asKey, bool abValue)
{

};

bool CRegistryUnix::GetBool(const char *asKey) const
{
    return false;
};