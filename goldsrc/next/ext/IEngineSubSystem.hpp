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

#pragma once

#include <next/CommonTypes.hpp>
#include <tier1/interface.h>

// TODO: IAppSystem? ISubSystem? IEngineSystem?
interface IEngineSubSystem // TODO: : public IBaseInterface?
{
	///
	virtual bool Connect(CreateInterfaceFn afnEngineFactory) = 0;
	
	///
	virtual void Disconnect() = 0;
	
	//
	// TODO: return void ptr?
	virtual IBaseInterface *QueryInterface(const char *asInterfaceName) = 0;
	
	template <typename T>
	T *QueryInterface(const char *asInterfaceName){return reinterpret_cast<T*>(QueryInterface(asInterfaceName));}
	
	///
	//virtual bool Init() = 0; // TODO: var args support?
	
	// Shutdown the subsystem/module
	/// Oportunity to flush and close any open files
	virtual void Shutdown() = 0;
};