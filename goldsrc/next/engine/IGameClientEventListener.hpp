/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2018-2020, 2022 BlackPhrase
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
/// @brief game client event listener interface

#pragma once

#include <CommonTypes.hpp>

interface IGameClientEventListener
{
	///
	//virtual void Release() = 0;
	
	///
	virtual bool OnClientConnect(int clientid, const char *name, const char *adr, char sRejectReason[128]) = 0;
	
	///
	virtual void OnClientDisconnect(int clientid) = 0;
	
	///
	//virtual void OnClientKill(int clientid) = 0;
	
	///
	virtual void OnClientPutInServer(int clientid) = 0;
	
	///
	virtual void OnClientCommand(int clientid, const ICmdArgs &apArgs) = 0;
	
	///
	virtual void OnClientUserInfoChanged(int clientid, char *userinfo) = 0;
};