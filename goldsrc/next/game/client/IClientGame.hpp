/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2015-2018, 2020, 2022, 2024 BlackPhrase
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
/// @brief client-side game interface (interface that client game module exposes to the engine)

#pragma once

#include <next/ext/IEngineSubSystem.hpp>

constexpr auto OGS_CLIENTGAME_INTERFACE_VERSION{"OGSClientGame002"};

interface IClientGame : public IEngineSubSystem
{
	/// Initialize the client game module
	/// @param afnEngineFactory - engine interface factory
	/// @param pcl_funcs - pointer to client game module exports structure
	/// @return true if success, false if something went wrong (interface query failures, etc)
	virtual bool Init() = 0;
	//virtual bool Init(cldll_func_t *pcl_funcs) = 0;
	
	///
	virtual void Update() = 0;
	//virtual void Frame(double frametime) = 0;
};