/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2015-2020, 2022-2024 BlackPhrase
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
/// @brief server-side game interface(interface that game module exposes to the engine)

#pragma once

#include <next/ext/IEngineSubSystem.hpp>

constexpr auto OGS_GAME_INTERFACE_VERSION{"OGSGame002"};

interface INetMsg;

interface IGame : public IEngineSubSystem
{
	/**
	* Initialize the game for the first time
	*/
	virtual bool Init() = 0;
	
	/**
	* Shut down the entire game
	* Called once when the module is unloaded
	*/
	//virtual void Shutdown() = 0;
	
	/**
	*/
	//virtual void Update(float afTimeStep) = 0;
	//virtual void StartFrame() = 0;
	//virtual void Frame(double frametime) = 0;
	virtual void Update() = 0;
	
	// TODO: INetProtocol?
	
	///
	// TODO: temp?
	virtual void HandleClientMessage(int anClientID, int anMsgID) = 0;
	
	///
	// TODO: temp?
	virtual int GetNetProtocolVersion() const = 0;
	
	/// @return current game title string
	//virtual const char *GetDescription() const = 0;
};