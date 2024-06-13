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

VSTDLIB_INTERFACE void *Coroutine_Create();
VSTDLIB_INTERFACE void Coroutine_Cancel(void *);

VSTDLIB_INTERFACE void Coroutine_Continue(void *);

VSTDLIB_INTERFACE bool Coroutine_IsActive(void *);

VSTDLIB_INTERFACE void Coroutine_DebugBreak(void *);

VSTDLIB_INTERFACE void Coroutine_ReleaseThreadMemory(int);

VSTDLIB_INTERFACE void Coroutine_Test();

VSTDLIB_INTERFACE void Coroutine_ValidateGlobals();
VSTDLIB_INTERFACE void Coroutine_YieldToMain();

VSTDLIB_INTERFACE void *Coroutine_GetCurrentlyActive();
VSTDLIB_INTERFACE int Coroutine_GetStackDepth();