#ifndef _SIMAGE_RGB_H_
#define _SIMAGE_RGB_H_

/*
 * Copyright (c) Kongsberg Oil & Gas Technologies
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#ifndef SIMAGE_RGB_SUPPORT
#error "This file should not be used under the current configuration!"
#endif /* !SIMAGE_RGB_SUPPORT */

#ifdef __cplusplus
extern "C" {
#endif

  unsigned char * simage_rgb_load(const char * filename,
                                  int * width,
                                  int * height,
                                  int * numcomponents);
  int simage_rgb_save(const char * filename,
                      const unsigned char * bytes,
                      int width,
                      int height,
                      int numcomponents);
  int simage_rgb_identify(const char * filename,
                          const unsigned char * header,
                          int headerlen);

  int simage_rgb_error(char * buffer, int bufferlen);

/* new for simage 1.6 */
  void * simage_rgb_open(const char * filename,
                         int * width,
                         int * height,
                         int * numcomponents);
  void simage_rgb_close(void * opendata);
  int simage_rgb_read_line(void * opendata, int y, unsigned char * buf);

#ifdef __cplusplus
}
#endif

#endif /* _SIMAGE_RGB_H_ */
