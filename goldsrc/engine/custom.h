/*
 * This file is part of OGS Engine
 * Copyright (C) 2018-2019, 2021 BlackPhrase
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

#pragma once

#include "const.h"

#define MAX_QPATH 64 // Must match value in quakedef.h

/// Resource flags
#define RES_CUSTOM (1 << 2)

typedef enum
{
	t_sound = 0,
	t_skin,
	t_model,
	t_decal,
	t_generic,
	t_eventscript,
	t_world ///< Alias for t_model (BSP world is also a model)
} resourcetype_t;

typedef struct
{
	int size;
} _resourceinfo_t;

#define MAX_RESOURCEINFO 8 // == size of resourcetype_t?

typedef struct resourceinfo_s
{
	_resourceinfo_t info[MAX_RESOURCEINFO];
} resourceinfo_t;

typedef struct resource_s
{
	char szFileName[MAX_QPATH]; ///< File name to download/precache
	resourcetype_t type; ///< Type of the resource (sound, skin, model, decal, etc)
	int nIndex; ///< Decal index (for decals)
	int nDownloadSize; ///< Size in bytes if this must be downloaded
	byte ucFlags;
	
	byte rgucMD5_hash[16]; ///< To determine if we already have it
	byte playernum; ///< Which player index this resource is associated with, if it's a custom resource
	
	byte rguc_reserved[32]; // For future expansion
	
	struct resource_s *pNext; ///< Next in chain
	struct resource_s *pPrev; ///< Previous in chain
} resource_t;

typedef struct customization_s
{
	qboolean bInUse; ///< Is this customization in use
	resource_t resource; ///< The resource for this customization
	qboolean bTranslated; ///< Has the raw data been translated info a usable format?
	
	int nUserData1; ///< Customzation-specific data
	int nUserData2; ///< More customzation-specific data
	
	void *pInfo;
	void *pBuffer;
	
	struct customization_s *pNext; ///< Next in chain
} customization_t;

#define FCUST_FROMHPAK (1 << 0)
#define FCUST_WIPEDATA (1 << 1)
#define FCUST_IGNOREINIT (1 << 2)

void COM_ClearCustomizationList(struct customization_s *pHead, qboolean bClearDecals);
qboolean COM_CreateCustomization(struct customization_s *pListHead, struct resource_s *pResource, int nPlayerNum, int nFlags, struct customization_s **pCustomization, int *nLumps);
int COM_SizeofResourceList(struct resource_s *pList, struct resourceinfo_s *pResInfo);