/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2017-2018, 2020 BlackPhrase
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
/// @brief GameUI functions interface

#pragma once

#include "CommonTypes.hpp"
#include "tier1/interface.h"

constexpr auto OGS_GAMEUIFUNCS_INTERFACE_VERSION{"OGSGameUIFuncs001"};

interface IGameUIFuncs : public IBaseInterface
{
	///
	virtual bool IsKeyDown( const char *keyname, bool& isdown ) = 0;
	
	///
	virtual const char *GetBindingForButtonCode( ButtonCode_t code ) = 0;
	
	///
	virtual ButtonCode_t GetButtonCodeForBind( const char *pBind ) = 0;
	
	///
	virtual void GetVideoModes( struct vmode_s **liststart, int *count ) = 0;
	
	///
	virtual void SetFriendsID( uint friendsID, const char *friendsName ) = 0;
	
	///
	virtual void GetDesktopResolution( int &width, int &height ) = 0;
	
	///
	//virtual bool IsConnectedToVACSecureServer() = 0;
};

/*
class IGameUIFuncs : public IBaseInterface
{
public:
	virtual const char *Key_NameForKey(int keynum) = 0;
	virtual const char *Key_BindingForKey(int keynum) = 0;
	virtual vgui::KeyCode GetVGUI2KeyCodeForBind(const char *bind) = 0;
	virtual void GetVideoModes(struct vmode_s **liststart, int *count) = 0;
	virtual void GetCurrentVideoMode(int *wide, int *tall, int *bpp) = 0;
	virtual void GetCurrentRenderer(char *name, int namelen, int *windowed) = 0;
	
	virtual int Key_KeyStringToKeyNum(const char *string) = 0;
};
*/