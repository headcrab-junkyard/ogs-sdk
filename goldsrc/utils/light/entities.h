/*
 * This file is part of OGS Engine
 * Copyright (C) 1996-1997 Id Software, Inc.
 * Copyright (C) 2022 BlackPhrase
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

#define DEFAULTLIGHTLEVEL	300

typedef struct epair_s
{
	struct epair_s	*next;
	char	key[MAX_KEY];
	char	value[MAX_VALUE];
} epair_t;

typedef struct entity_s
{
	char	classname[64];
	vec3_t	origin;
	float	angle;
	int		light;
	int		style;
	char	target[32];
	char	targetname[32];
	struct epair_s	*epairs;
	struct entity_s	*targetent;
} entity_t;

extern	entity_t	entities[MAX_MAP_ENTITIES];
extern	int			num_entities;

char 	*ValueForKey (entity_t *ent, char *key);
void 	SetKeyValue (entity_t *ent, char *key, char *value);
float	FloatForKey (entity_t *ent, char *key);
void 	GetVectorForKey (entity_t *ent, char *key, vec3_t vec);

void LoadEntities (void);
void WriteEntitiesToString (void);
