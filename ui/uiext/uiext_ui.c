/* null_ui.c: Routines for dealing with the null user interface
   Copyright (c) 2017 Philip Kendall

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Author contact information:

   E-mail: philip-fuse@shadowmagic.org.uk

*/

#include <string.h>

#include "config.h"
#include "keyboard.h"
#include "ui/ui.h"
#include "ui/uijoystick.c"
#include "fuse.h"
#include "settings.h"
#include "timer/timer.h"

libspectrum_byte fuzx_image[DISPLAY_SCREEN_HEIGHT][DISPLAY_SCREEN_WIDTH];
static libspectrum_byte temp_fuzx_image[DISPLAY_SCREEN_HEIGHT][DISPLAY_SCREEN_WIDTH];

// keysyms_map_t keysyms_map[] = {
//   { 0, 0 } /* End marker */
// };

// scaler_type
// menu_get_scaler( scaler_available_fn selector )
// {
//   /* No scaler selected */
//   return SCALER_NUM;
// }

// int
// menu_select_roms_with_title( const char *title, size_t start, size_t count,
//     int is_peripheral )
// {
//   /* No error */
//   return 0;
// }

// void
// ui_breakpoints_updated( void )
// {
//   /* Do nothing */
// }

// ui_confirm_save_t
// ui_confirm_save_specific( const char *message )
// {
//   return UI_CONFIRM_SAVE_DONTSAVE;
// }

// ui_confirm_joystick_t
// ui_confirm_joystick( libspectrum_joystick libspectrum_type, int inputs )
// {
//   return UI_CONFIRM_JOYSTICK_NONE;
// }

// int
// ui_debugger_activate( void )
// {
//   /* No error */
//   return 0;
// }

// int
// ui_debugger_deactivate( int interruptable )
// {
//   /* No error */
//   return 0;
// }

// int
// ui_debugger_disassemble( libspectrum_word addr )
// {
//   /* No error */
//   return 0;
// }

// int
// ui_debugger_update( void )
// {
//   /* No error */
//   return 0;
// }


int ui_init(int *argc, char ***argv) {
    return 0;
}

int ui_end(void) {
    return 0;
}

// int
// ui_error_specific( ui_error_level severity, const char *message )
// {
//   /* No error */
//   return 0;
// }

int ui_event(void) {
    return 0;
}

// char*
// ui_get_open_filename( const char *title )
// {
//   /* No filename */
//   return NULL;
// }

// int
// ui_get_rollback_point( GSList *points )
// {
//   /* No rollback point */
//   return -1;
// }

// char*
// ui_get_save_filename( const char *title )
// {
//   /* No filename */
//   return NULL;
// }

// int
// ui_menu_item_set_active( const char *path, int active )
// {
//   /* No error */
//   return 0;
// }

int ui_mouse_grab(int startup) {
    /* Successful grab */
    return 1;
}

int ui_mouse_release(int suspend) {
    /* No error */
    return 0;
}

// void
// ui_pokemem_selector( const char *filename )
// {
//   /* Do nothing */
// }

// int
// ui_query( const char *message )
// {
//   /* Query confirmed */
//   return 1;
// }

// int
// ui_statusbar_update( ui_statusbar_item item, ui_statusbar_state state )
// {
//   /* No error */
//   return 0;
// }

// static int __counter_ui_statusbar_update_speed = 0;

// int
// ui_statusbar_update_speed( float speed )
// {
//   if (__counter_ui_statusbar_update_speed++ == 50) {
//     printf("speed %.0f\n", speed);
//     __counter_ui_statusbar_update_speed = 0;
//   }
//   /* No error */
//   return 0;
// }

// int
// ui_tape_browser_update( ui_tape_browser_update_type change,
//     libspectrum_tape_block *block )
// {
//   /* No error */
//   return 0;
// }

// int
// ui_widgets_reset( void )
// {
//   /* No error */
//   return 0;
// }

void uidisplay_area(int x, int y, int w, int h) {
    libspectrum_byte *src = &temp_fuzx_image[y][x];
    libspectrum_byte *dest = &fuzx_image[y][x];
    for (int i = 0; i < h; i++) {
        memcpy(dest, src, w);
        src += DISPLAY_SCREEN_WIDTH;
        dest += DISPLAY_SCREEN_WIDTH;
    }
}

void uidisplay_frame_end(void) {
    /* Do nothing */
}

int uidisplay_hotswap_gfx_mode(void) {
    /* No error */
    return 0;
}

int uidisplay_init(int width, int height) {
    /* No error */
    return 0;
}

int uidisplay_end(void) {
    /* No error */
    return 0;
}

void uidisplay_plot16(int x, int y, libspectrum_word data, libspectrum_byte ink,
                      libspectrum_byte paper) {
    /* Do nothing */
}

void uidisplay_plot8(int x, int y, libspectrum_byte data, libspectrum_byte ink,
                     libspectrum_byte paper) {
    x <<= 3;
    libspectrum_byte *dest = &temp_fuzx_image[y][x];
    *(dest++) = (data & 0x80) ? ink : paper;
    *(dest++) = (data & 0x40) ? ink : paper;
    *(dest++) = (data & 0x20) ? ink : paper;
    *(dest++) = (data & 0x10) ? ink : paper;
    *(dest++) = (data & 0x08) ? ink : paper;
    *(dest++) = (data & 0x04) ? ink : paper;
    *(dest++) = (data & 0x02) ? ink : paper;
    *dest = (data & 0x01) ? ink : paper;
}

void uidisplay_putpixel(int x, int y, int colour) {
    temp_fuzx_image[y][x] = colour;
}

void uidisplay_frame_save(void) {
}

void uidisplay_frame_restore(void) {
}

/* --- fusex embedding stubs ----------------------------------------------
   fusex expects the platform app (fusepb on macOS, win32ui on Windows) to
   provide these; the headless uiext build supplies no-op versions. */

#include "menu.h"

/* fusepb drives the emulation timer from this; headless builds pace frames
   externally (or not at all). */
void
SetEmulationHz( float hz )
{
}

/* Sparkle/WinSparkle updater hook referenced from the generated menus. */
MENU_CALLBACK( menu_help_check_for_updates )
{
}

#ifdef __APPLE__
/* ui.c compiles these out under #ifndef __APPLE__, assuming the Cocoa app
   implements them. Headless builds need no-op versions. */
int
ui_menu_activate( ui_menu_item item, int active )
{
  return 0;
}

int
ui_tape_write( void )
{
  return 0;
}

int
ui_disk_write( int which, int saveas )
{
  return 0;
}

int
ui_mdr_write( int which, int saveas )
{
  return 0;
}
#endif /* #ifdef __APPLE__ */

#ifndef UI_WIN32
/* fusex renamed the portable main() to old_main() because fusepb owns
   main(); the standalone fuse binary still needs one. */
int old_main( int argc, char **argv );

int
main( int argc, char **argv )
{
  return old_main( argc, argv );
}
#endif

#ifndef BUILD_SPECTRANET
/* debugger/vfile.c references the RAM xfs engine unconditionally, but the
   real engine (peripherals/fs/) only builds with Spectranet. The gdbserver
   vFile interface is unused in headless builds; fail all operations. */
#include "peripherals/fs/xfs.h"

static int16_t
uiext_xfs_stub_mount( const struct xfs_engine_t *engine, const char *hostname,
                      const char *path, struct xfs_engine_mount_t *out_mount )
{
  return XFS_ERR_IO;
}

static int16_t
uiext_xfs_stub_close( const struct xfs_engine_mount_t *mount,
                      struct xfs_handle_t *handle )
{
  return XFS_ERR_OK;
}

static void
uiext_xfs_stub_free_handle( const struct xfs_engine_mount_t *mount,
                            struct xfs_handle_t *handle )
{
}

struct xfs_engine_t xfs_ram_engine = {
  .mount = uiext_xfs_stub_mount,
  .close = uiext_xfs_stub_close,
  .closedir = uiext_xfs_stub_close,
  .free_handle = uiext_xfs_stub_free_handle,
};

void
xfs_reset( void )
{
}
#endif /* #ifndef BUILD_SPECTRANET */
