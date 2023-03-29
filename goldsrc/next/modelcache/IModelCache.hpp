/*
 * This file is part of OGS SDK
 *
 * Copyright (C) 2023 BlackPhrase
 *
 * OGS SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS SDK. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#pragma once

#include <next/CommonTypes.hpp>
#include <tier1/interface.h>

constexpr auto OGS_MODELCACHE_INTERFACE_VERSION{"OGSModelCache001"};

interface IModelCache : public IBaseInterface
{
	///
	virtual int PrecacheModel(const char *asName) = 0;
	
	///
	virtual IModel *Find(const char *asName) const = 0;
};