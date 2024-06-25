/*
 * This file is part of OpenLambda Project
 *
 * Copyright (C) 2019, 2022, 2024 BlackPhrase
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
/// @brief game event dispatcher interface

#pragma once

#include <next/CommonTypes.hpp>
#include <tier1/interface.h>

constexpr auto OGS_GAMEEVENTDISPATCHERCLIENT_INTERFACE_VERSION{"OGSGameEventDispatcherClient001"};
constexpr auto OGS_GAMEEVENTDISPATCHERSERVER_INTERFACE_VERSION{"OGSGameEventDispatcherServer001"};

interface IGameEvent;
interface IGameEventListener;

interface IGameEventDispatcher : public IBaseInterface
{
	///
	virtual void AddListener(IGameEventListener *apListener) = 0;
	
	///
	virtual void RemoveListener(IGameEventListener *apListener) = 0;
	
	/// Notify listeners about the event locally (either on client or server sides)
	virtual bool FireEvent(IGameEvent *apEvent) = 0;
};

interface IGameEventDispatcherServer : public IGameEventManager
{
	/// Notify listeners about the event, including all the connected clients
	virtual void BroadcastEvent(IGameEvent *apEvent) = 0;
};