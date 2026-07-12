/* extsound.c: streaming sound for using FUSE as a library
   Copyright (c) 2024 Ruslan Grohovetcki

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

*/

#include "config.h"

#include "fuse.h"
#include "sfifo.h"

#include <stdio.h>


#define EXTSOUND_BUFSIZE 16384

sfifo_t sound_fifo;

int
extsound_read( void *data, int max_len )
{
  // printf("extsound_read max_length %d\n", max_len);
  return sfifo_read(&sound_fifo, data, max_len);
}

int
extsound_fifo_used( void )
{
  return sfifo_used(&sound_fifo);
}

int
sound_lowlevel_init( const char *device, int *freqptr, int *stereoptr )
{
  *stereoptr = 1;
  // printf("sound_lowlevel_init for device %s, freq %d, stereo %d\n", device, *freqptr, *stereoptr);

  sfifo_init( &sound_fifo, EXTSOUND_BUFSIZE );

  return 0;
}

void
sound_lowlevel_end( void )
{
  // printf("sound_lowlevel_end\n");
  sfifo_flush( &sound_fifo );
  sfifo_close( &sound_fifo );
}

void
sound_lowlevel_frame( unsigned char *data, int len )
{
  int i;

  // printf("sound_lowlevel_frame legth %d\n", len);
  libspectrum_signed_byte *bytes = (libspectrum_signed_byte*)data;
  len <<= 1;

  while(len) {
    if( ( i = sfifo_write( &sound_fifo, bytes, len ) ) < 0 ) {
      break;
    } else if ( !i ) {
      printf("sfifo is full\n");
      break;
    }
    bytes += i;
    len -= i;
  }

}
