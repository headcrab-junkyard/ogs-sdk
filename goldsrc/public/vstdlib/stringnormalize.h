/*
 * This file is part of OGS Engine SDK
 * Copyright (C) 2024 BlackPhrase
 *
 * OGS Engine SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine SDK. If not, see <http://www.gnu.org/licenses/>.
 */

/// @file

#pragma once

#include "vstdlib.h"

class CValidator;

// TODO: make private?
class VSTDLIB_CLASS CStringNormalization
{
public:
	// NOTE: assignment operator
	
	void Initialize();
	
	int Normalize(bool, const char *src, char *dest, int buflen);
	int Normalize(bool, const wchar_t *src, wchar_t *dest, int buflen);
	
	bool Test_BValidateStructures();
	
	void ValidateStatics(CValidator &, char *);
//private:
	bool m_bInitialized{false}; // TODO: make private?
};