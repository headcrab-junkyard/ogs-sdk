/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2017-2018, 2020, 2022 BlackPhrase
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
/// @brief system event listener interface

#pragma once

#include <CommonTypes.hpp>

interface ISystemEventListener
{
	///
	//virtual void Release() = 0;
	
	///
	virtual void OnError(const char *text) = 0; // {}
	
	///
	//virtual uint OnStorageDeviceAttached() = 0;
	
	///
	//virtual void OnStorageDeviceDetached() = 0;
};