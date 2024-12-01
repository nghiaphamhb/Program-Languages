#ifndef IMAGE 
#define IMAGE

#include <stdint.h>
#include <stdlib.h>

#include "utils.h"
#include "bmp.h"

struct image {
  uint64_t width, height;
  struct pixel* data;
};

struct image create_image(uint64_t width, uint64_t height);
void destroy_image(struct image** image);  
size_t get_image_size(const struct image *img);
size_t get_padding(const struct image *img);

#endif