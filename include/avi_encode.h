#ifndef AVI_ENCODE_H_
#define AVI_ENCODE_H_

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

#ifndef SIMAGE_AVIENC_SUPPORT
#error "This file should not be used under the current configuration!"
#endif /* !SIMAGE_AVIENC_SUPPORT */

#ifdef __cplusplus
extern "C" {
#endif

  void * avi_begin_encode(const char *filename, int width, int height, int fps, const char *preferences_filename);
  int avi_encode_bitmap(void *handle, unsigned char *buf, int rgb2bgr);
  int avi_end_encode(void *handle);

#ifdef __cplusplus
}
#endif

#endif /* AVI_ENCODE_H_ */

