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

#ifdef __alpha
#include <pthread.h>
extern	pthread_mutex_t	*my_mutex;
#define	LOCK	pthread_mutex_lock (my_mutex)
#define	UNLOCK	pthread_mutex_unlock (my_mutex)
#else
#define	LOCK
#define	UNLOCK
#endif

extern	int		numthreads;

typedef void (threadfunc_t) (void *);

void InitThreads (void);
void RunThreadsOn ( threadfunc_t func );
