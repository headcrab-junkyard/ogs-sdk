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

#include "cmdlib.h"
#include "mathlib.h"
#include "bspfile.h"

void main (int argc, char **argv)
{
	int			i;
	char		source[1024];

	if (argc == 1)
		Error ("usage: bspinfo bspfile [bspfiles]");
		
	for (i=1 ; i<argc ; i++)
	{
		printf ("---------------------\n");
		strcpy (source, argv[i]);
		DefaultExtension (source, ".bsp");
		printf ("%s\n", source);
		
		LoadBSPFile (source);		
		PrintBSPFileSizes ();
		printf ("---------------------\n");
	}
}
