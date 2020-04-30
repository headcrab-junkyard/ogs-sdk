/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2015-2020 BlackPhrase
 *
 * OGSNext Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGSNext Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGSNext Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @brief engine plugin interface

#pragma once

#include "CommonTypes.hpp"
#include "tier1/interface.h"

constexpr auto OGS_ENGINEPLUGIN_INTERFACE_VERSION{"OGSEnginePlugin005"};

/// Callbacks the engine exposes to the 3rd party plugins
interface IEnginePlugin : public IBaseInterface
{
	/**
	* Called when plugin is loading
	*
	* @param afnModuleFactory - module factory from the engine
	* @return false if there is an error during load
	*/
	virtual bool Load(CreateInterfaceFn afnModuleFactory) = 0;
	
	/// Called when unloading the plugin
	virtual void Unload() = 0;
	
	/// @return interface factory from the plugin
	virtual CreateInterfaceFn GetFactory() const = 0;
	
	/// Engine plugin info struct
	struct Info
	{
		const char *sName{""};        ///< Plugin name
		const char *sVersion{""};     ///< Version string
		const char *sAuthor{""};      ///< Author name
		const char *sDescription{""}; ///< Description
		
		//bool bClientSide{false};      ///< Set it to true if the plugin is meant for client-side only
	};
	
	/**
	* Get info about the plugin
	*
	* @param apInfo - plugin info struct passed from engine to fill it's fields by the plugin
	*/
	virtual void GetInfo(Info &apInfo) = 0;
};