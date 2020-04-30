/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2020 BlackPhrase
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

#pragma once

#include "tier1/interface.h"

constexpr auto OGS_PLAYERMOVE_CLIENT_INTERFACE_VERSION{"OGSPlayerMoveClient001"};
constexpr auto OGS_PLAYERMOVE_SERVER_INTERFACE_VERSION{"OGSPlayerMoveServer001"};

struct IPlayerMove : public IBaseInterface
{
	///
	virtual void Init(struct playermove_s *ppmove) = 0;
	
	///
	virtual void Move(struct playermove_s *ppmove) = 0;
	
	///
	virtual char GetTextureType(const char *name) const = 0;
};