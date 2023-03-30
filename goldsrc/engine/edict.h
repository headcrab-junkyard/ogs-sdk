/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2018, 2023 BlackPhrase
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

#include <common/const.h>
#include <common/entity_state.h>

#include "progdefs.h"

#define	MAX_ENT_LEAFS 48

typedef struct edict_s
{
	qboolean free;
	int serialnumber; // TODO
	
	link_t area; ///< Linked to a division node or leaf
	
	int headnode; ///< -1 to use normal leaf check // TODO
	
	int num_leafs;
	short leafnums[MAX_ENT_LEAFS];
	
	//entity_state_t baseline; // TODO: remove
	
	float freetime; ///< sv.time when the object was freed
	
	void *pvPrivateData; ///< Allocated and released by engine module, used by game module // TODO
	
	entvars_t v; ///< C exported fields from progs
	
	// Other fields from progs come immediately after
} edict_t;