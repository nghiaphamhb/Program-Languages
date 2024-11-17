#ifndef IO
#define IO

#include <stdio.h>
#include <stdbool.h>

#include "bmp.h"
#include "image.h"
#include "utils.h"
#include "config.h"

/*  deserializer   */
enum read_status  {
  READ_OK = 0,
  READ_INVALID_SIGNATURE,
  READ_INVALID_BITS,
  READ_INVALID_HEADER
  /* коды других ошибок  */
  };

/*  serializer   */
enum  write_status  {
  WRITE_OK = 0,
  WRITE_ERROR
  /* коды других ошибок  */
};

bool read_header(FILE *in, struct bmp_header *const header);
bool read_data(FILE *in, const struct image *const img);
enum read_status from_bmp( FILE* in, struct image* img );

bool write_header(FILE* out, const struct image *const img);
bool write_data(FILE *in, const struct image *const img);
enum write_status to_bmp( FILE* out, struct image const* img );

#endif