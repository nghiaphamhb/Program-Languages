//hinh anh no bo
#ifndef IMAGE 
#define IMAGE

#include <stdint.h>
#include "bmp.h"

struct image {
  uint64_t width, height;
  struct pixel* data;
};


struct image create_image(uint64_t width, uint64_t height);
void destroy_image(struct image* image);  //"must be pointer to destroy" tan goc cua phan tu 
size_t image_size(struct image* img);
#endif