/*
 * This file is part of OpenLambda Project
 *
 * Copyright (C) 2019, 2022 BlackPhrase
 *
 * OpenLambda Project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenLambda Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenLambda Project. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#pragma once

#include <CommonTypes.hpp>
#include <tier1/interface.h>

constexpr auto OGS_GAMEVENTMANAGERCLIENT_INTERFACE_VERSION{"OGSGameEventManagerClient001"};
constexpr auto OGS_GAMEVENTMANAGERSERVER_INTERFACE_VERSION{"OGSGameEventManagerServer001"};

interface IGameEvent;

interface IGameEventManager : public IBaseInterface
{
	///
	virtual bool FireEvent(IGameEvent *apEvent) = 0;
};