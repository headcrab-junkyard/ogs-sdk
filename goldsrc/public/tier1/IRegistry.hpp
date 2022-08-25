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
/// @brief an interface to access the OS' registry

#pragma once

//constexpr auto OGS_REGISTRY_INTERFACE_VERSION{"OGSRegistry001"};

// TODO: Read the keys into CKeyValues class?

struct IRegistry
{
    ///
    virtual void SetString(const char *asKey, const char *asValue) = 0; // TODO: WriteString?

    ///
    virtual const char *GetString(const char *asKey) const = 0; // TODO: ReadString?

    ///
    virtual void SetInt(const char *asKey, int anValue) = 0; // TODO: WriteInt?

    ///
    virtual int GetInt(const char *asKey) const = 0; // TODO: ReadInt?

    ///
    virtual void SetBool(const char *asKey, bool abValue) = 0; // TODO: WriteBool?
    
    ///
    virtual bool GetBool(const char *asKey) const = 0; // TODO: ReadBool?
};

IRegistry *GetRegistry();