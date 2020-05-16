/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2017, 2020 BlackPhrase
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
/// @brief voice server interface

#pragma once

#include "CommonTypes.hpp"
#include "tier1/interface.h"

constexpr auto OGS_VOICESERVER_INTERFACE_VERSION{"OGSVoiceServer001"};

// TODO: IVoiceHandler/IVoiceController?
interface IVoiceServer : public IBaseInterface
{
	///
	virtual bool SetClientListening(/*const*/ int anReceiver, /*const*/ int anSender, /*const*/ bool abState) = 0;
	
	///
	virtual bool GetClientListening(/*const*/ int anReceiver, /*const*/ int anSender) const = 0;
};