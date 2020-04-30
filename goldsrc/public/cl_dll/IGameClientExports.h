/*
 * This file is part of OGS Engine
 * Copyright (C) 2018, 2020 BlackPhrase
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
/// @brief exports a set of functions for the GameUI module to interact with the game client

#pragma once

#include "tier1/interface.h"

constexpr auto GAMECLIENTEXPORTS_INTERFACE_VERSION{"GameClientExports001"};

struct IGameClientExports : public IBaseInterface
{
	/// @return the name of the server the user is connected to (if any)
	virtual const char *GetServerHostName() = 0;
	
	/// In-game voice manipulation
	virtual bool IsPlayerGameVoiceMuted(int anPlayerID) = 0;
	virtual void MutePlayerGameVoice(int anPlayerID) = 0;
	virtual void UnmutePlayerGameVoice(int anPlayerID) = 0;
};