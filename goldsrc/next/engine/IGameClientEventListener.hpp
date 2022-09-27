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
	
	/// Called when a client connects to the server
	/// @param anClientID - client index
	/// @param asName - client's preferred name string
	/// @param asAdr - client's net address string
	/// @param asRejectReason - a string used to store a reason in case this client was rejected by the server
	/// @return true if the client should be accepted by the server, false otherwise
	virtual bool OnClientConnect(int anClientID, const char *asName, const char *asAdr, char asRejectReason[128]) = 0;
	
	/// Called when a client is leaving the server
	/// @param anClientID - client index
	virtual void OnClientDisconnect(int anClientID) = 0;
	
	/// Called when client is entering the server after a successful connection and ready to play
	/// @param anClientID - client index
	virtual void OnClientPutInServer(int anClientID) = 0;
	
	/// Called when a client sent a command to the server
	/// @param anClientID - client index
	/// @param aArgs - the command's arguments
	virtual void OnClientCommand(int anClientID, const ICmdArgs &aArgs) = 0;
	
	/// Called after a client changed his user info
	/// @param anClientID - client index
	/// @param asUserInfo - client's new user info string
	virtual void OnClientUserInfoChanged(int anClientID, char *asUserInfo) = 0;
	
	/// Called when one of the files failed the consistency check for the specified client/player
	/// @param anClientID - client index
	/// @param asFileName - file name which failed the check
	/// @param asDisconnectMsg - a message which will be displayed to the client as a disconnect reason
	/// @return 0 to allow the client to continue, 1 to immediately disconnect him (an send an optional message of up to 256 chars in length)
	virtual int OnInconsistentFileFound(/*const*/ int anClientID, const char *asFileName, char *asDisconnectMsg) = 0;
	
	///
	virtual void OnClientCvarValueReceived(int anClientID, int anRequestID, const char *asCvarName, const char *asCvarValue) = 0;
};