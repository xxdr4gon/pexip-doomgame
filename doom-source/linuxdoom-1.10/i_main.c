// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: i_main.c,v 1.4 1997/02/03 22:45:10 b1 Exp $";



#include "doomdef.h"

#include "m_argv.h"
#include "d_main.h"

int app_proc_thread()
{
	return app_run( app_proc, 0, 0, 0, 0 );
}

int
main
( int		argc,
  char**	argv ) 
{ 
    myargc = argc; 
    myargv = argv; 
 
	#ifndef __wasm__
	#if defined( __TINYC__ )
		HMODULE kernel = LoadLibrary( "kernel32" );
		InitializeConditionVariable = GetProcAddress( kernel, "InitializeConditionVariable");
		WakeConditionVariable = GetProcAddress( kernel, "WakeConditionVariable");
		SleepConditionVariableCS = GetProcAddress( kernel, "SleepConditionVariableCS");
	#endif
	thread_signal_init( &vblank_signal );
    thread_mutex_init( &mus_mutex );
	#endif

	thread_atomic_int_store( &app_running, 1 );
	#ifdef _WIN32
		thread_create( app_proc_thread, 0, THREAD_STACK_SIZE_DEFAULT );
		thread_signal_wait( &vblank_signal, THREAD_SIGNAL_WAIT_INFINITE );
		D_DoomMain (); 
	#else 
		app_run( app_proc, 0, 0, 0, 0 );
	#endif    

    return 0;
} 
