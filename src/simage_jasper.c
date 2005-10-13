/*
 * a jasper importer/exporter
 * 
 */

#include <config.h>
#ifdef HAVE_JASPER

/* needed since Japser includes its own config file */
#undef PACKAGE
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef VERSION

#include <jasper/jasper.h>

#define ERR_NO_ERROR        0
#define ERR_OPEN            1
#define ERR_READ            2
#define ERR_MEM             3
#define ERR_OPEN_WRITE      4
#define ERR_WRITE           5
#define ERR_NOT_IMPLEMENTED 6

static int jaspererror = ERR_NO_ERROR;

int
simage_jasper_error(char * buffer, int buflen)
{
  switch (jaspererror) {
  case ERR_OPEN:
    strncpy(buffer, "JASPER loader: Error opening file", buflen);
    break;
  case ERR_READ:
    strncpy(buffer, "JASPER loader: Error reading file", buflen);
    break;
  case ERR_MEM:
    strncpy(buffer, "JASPER loader: Out of memory error", buflen);
    break;
  case ERR_OPEN_WRITE:
    strncpy(buffer, "JASPER saver: Error opening file", buflen);
    break;
  case ERR_WRITE:
    strncpy(buffer, "JASPER loader: Error writing file", buflen);
    break;
  case ERR_NOT_IMPLEMENTED:
    strncpy(buffer, "JASPER loader: Feature not implemented", buflen);
    break;
  }
  return jaspererror;
}

int 
simage_jasper_identify(const char *ptr,
                       const unsigned char * header,
                       int headerlen)
{
  static unsigned char jaspercmp[] = {0x50, 0x35, 0xa};
  
  if (headerlen < 3) return 0;
  if (memcmp((const void*)header, (const void*)jaspercmp, 3) == 0) return 1;
  return 0;
}

unsigned char *
simage_jasper_load(const char * filename,
                   int * width_ret,
                   int * height_ret,
                   int * numComponents_ret)
{
  jaspererror = ERR_NOT_IMPLEMENTED;
  return NULL;
}

int 
simage_jasper_save(const char *filename,
                   const unsigned char * bytes,
                   int width,
                   int height,
                   int numcomponents)
{
  jaspererror = ERR_NOT_IMPLEMENTED;
  return 0;
}

typedef struct {
  int width;
  int height;
  int numcomp;
  int depth;
  
} simage_jasper_opendata;

void * 
simage_jasper_open(const char * filename,
                   int * width,
                   int * height,
                   int * numcomponents)
{
  jaspererror = ERR_NOT_IMPLEMENTED;
  return NULL;
}


void 
simage_jasper_close(void * opendata)
{
  simage_jasper_opendata * od = (simage_jasper_opendata*) opendata;
  jaspererror = ERR_NOT_IMPLEMENTED;
}

int 
simage_jasper_read_line(void * opendata, int y, unsigned char * buf)
{
  simage_jasper_opendata * od;
  jaspererror = ERR_NOT_IMPLEMENTED;
   
  od = (simage_jasper_opendata*) opendata;
  return 0;
}

#endif /* HAVE_JASPER */
