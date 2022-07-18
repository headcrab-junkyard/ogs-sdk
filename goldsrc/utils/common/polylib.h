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

typedef struct
{
	int		numpoints;
	vec3_t	p[4];		// variable sized
} winding_t;

#define	MAX_POINTS_ON_WINDING	64

#define	ON_EPSILON	0.1

winding_t	*AllocWinding (int points);
vec_t	WindingArea (winding_t *w);
void	WindingCenter (winding_t *w, vec3_t center);
void	ClipWinding (winding_t *in, vec3_t normal, vec_t dist,
					 winding_t **front, winding_t **back);
winding_t	*ChopWinding (winding_t *in, vec3_t normal, vec_t dist);
winding_t	*CopyWinding (winding_t *w);
winding_t	*BaseWindingForPlane (vec3_t normal, float dist);
void	CheckWinding (winding_t *w);
void	WindingPlane (winding_t *w, vec3_t normal, vec_t *dist);
void	RemoveColinearPoints (winding_t *w);
