#pragma warning( disable: 4113 )
#pragma warning( disable: 4311 )
#pragma warning( disable: 4047 )
#pragma warning( disable: 4024 )
#pragma warning( disable: 4312 )
#pragma warning( disable: 4020 )
#pragma warning( disable: 4700 )
#pragma warning( disable: 4133 )
#pragma warning( disable: 4142 )

#ifdef _WIN32
#define strcasecmp stricmp
#define strncasecmp strnicmp
#else
#include <strings.h>	
#endif

#define CONCAT_IMPL( x, y ) x##y
#define CONCAT( x, y ) CONCAT_IMPL( x, y )
#define rcsid CONCAT( rcsid, __COUNTER__ )


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int doom_access( char const* _FileName, int _AccessMode ) {
    FILE* f = fopen( _FileName, "rb" );
    if( f ) {
        fclose(f);
        return 0;
    }
    return 1;
}
#ifdef _WIN32
	#include "libs_win32/unistd.h"
#else 
	#include <unistd.h>
#endif

#undef access
#define access doom_access

#define open doom_open
#define close doom_close

#include "linuxdoom-1.10/am_map.c"
#include "linuxdoom-1.10/doomdef.c"
#include "linuxdoom-1.10/doomstat.c"
#include "linuxdoom-1.10/dstrings.c"
#include "linuxdoom-1.10/d_items.c"
#include "linuxdoom-1.10/d_main.c"
#include "linuxdoom-1.10/d_net.c"
#include "linuxdoom-1.10/f_finale.c"
#include "linuxdoom-1.10/f_wipe.c"
#include "linuxdoom-1.10/g_game.c"
#include "linuxdoom-1.10/hu_lib.c"
#include "linuxdoom-1.10/hu_stuff.c"
#include "linuxdoom-1.10/info.c"
#include "linuxdoom-1.10/m_argv.c"
#include "linuxdoom-1.10/m_bbox.c"
#include "linuxdoom-1.10/m_cheat.c"
#include "linuxdoom-1.10/m_fixed.c"
#include "linuxdoom-1.10/m_random.c"
#include "linuxdoom-1.10/m_swap.c"
#include "linuxdoom-1.10/p_ceilng.c"
#include "linuxdoom-1.10/p_doors.c"
#include "linuxdoom-1.10/p_enemy.c"
#include "linuxdoom-1.10/p_floor.c"
#include "linuxdoom-1.10/p_inter.c"
#include "linuxdoom-1.10/p_lights.c"
#include "linuxdoom-1.10/p_map.c"
#include "linuxdoom-1.10/p_maputl.c"
#include "linuxdoom-1.10/p_mobj.c"
#include "linuxdoom-1.10/p_plats.c"
#include "linuxdoom-1.10/p_pspr.c"
#include "linuxdoom-1.10/p_saveg.c"
#include "linuxdoom-1.10/p_setup.c"
#include "linuxdoom-1.10/p_sight.c"
#include "linuxdoom-1.10/p_spec.c"
#include "linuxdoom-1.10/p_switch.c"
#include "linuxdoom-1.10/p_telept.c"
#include "linuxdoom-1.10/p_tick.c"
#include "linuxdoom-1.10/p_user.c"
#include "linuxdoom-1.10/r_bsp.c"
#include "linuxdoom-1.10/r_data.c"
#include "linuxdoom-1.10/r_draw.c"
#include "linuxdoom-1.10/r_main.c"
#include "linuxdoom-1.10/r_plane.c"
#include "linuxdoom-1.10/r_segs.c"
#include "linuxdoom-1.10/r_sky.c"
#include "linuxdoom-1.10/r_things.c"
#include "linuxdoom-1.10/sounds.c"
#undef BG
#include "linuxdoom-1.10/st_lib.c"
#include "linuxdoom-1.10/st_stuff.c"
#define channels xchannels
#include "linuxdoom-1.10/s_sound.c"
#undef channels
#include "linuxdoom-1.10/tables.c"
#include "linuxdoom-1.10/v_video.c"
#define anim_t wi_anim_t
#define anims wi_anims
#define time wi_time
#include "linuxdoom-1.10/wi_stuff.c"
#undef anims
#undef anim_t
#undef time
#include "linuxdoom-1.10/z_zone.c"

#undef open
#undef close

#include "linuxdoom-1.10/m_menu.c"
#include "linuxdoom-1.10/m_misc.c"
#define strupr xstrupr
#include "linuxdoom-1.10/w_wad.c"
#undef strupr

#include "linuxdoom-1.10/i_net.c"

#undef MAXCHAR
#undef MAXSHORT
#undef MAXINT
#undef MAXLONG
#undef MINCHAR
#undef MINSHORT
#undef MININT
#undef MINLONG

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#ifdef __wasm__
#define APP_WASM
#define WA_CORO_IMPLEMENT_NANOSLEEP
#else
#define APP_WINDOWS
#endif
#define APP_LOG( ctx, level, message )
#define boolean HACK_TO_MAKE_BOOLEAN_NOT_BE_DEFINED
#define APP_IMPLEMENTATION
#include "libs_win32/app.h"
#undef APP_IMPLEMENTATION

#define FRAMETIMER_IMPLEMENTATION
#include "libs_win32/frametimer.h"

#define CRTEMU_IMPLEMENTATION
#include "libs_win32/crtemu.h"

#ifndef __wasm__
#define THREAD_IMPLEMENTATION
#if defined( __TINYC__ )
	typedef struct _RTL_CONDITION_VARIABLE { PVOID Ptr; } RTL_CONDITION_VARIABLE, *PRTL_CONDITION_VARIABLE;
	typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;
	static VOID (*InitializeConditionVariable)( PCONDITION_VARIABLE );
	static VOID (*WakeConditionVariable)( PCONDITION_VARIABLE );
	static BOOL (*SleepConditionVariableCS)( PCONDITION_VARIABLE, PCRITICAL_SECTION, DWORD );
#endif
#include "libs_win32/thread.h"
#undef THREAD_IMPLEMENTATION
#endif

#undef boolean 

#define MUS_IMPLEMENTATION
#include "libs_win32/mus.h"

#define TSF_IMPLEMENTATION
#define TSF_POW     pow
#define TSF_POWF    (float)pow
#define TSF_EXPF    (float)exp
#define TSF_LOG     log
#define TSF_TAN     tan
#define TSF_LOG10   log10
#define TSF_SQRT   (float)sqrt
#define TSF_SQRTF   (float)sqrt
#include <math.h>
#include "libs_win32/tsf.h"

#include "libs_win32/soundfont.c"

#ifdef __wasm__
WaCoro user_coro;
WA_EXPORT(user_thread_proc) int user_thread_proc( void* user_data ) {
	D_DoomMain (); 
    return 0;
}
#endif

#include "linuxdoom-1.10/i_sound.c"
#include "linuxdoom-1.10/i_video.c"
#include "linuxdoom-1.10/i_system.c"

#include "linuxdoom-1.10/i_main.c"
