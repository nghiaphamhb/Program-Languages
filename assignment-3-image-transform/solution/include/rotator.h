#ifndef ROT
#define ROT

#include <string.h>

#include "config.h"
#include "image.h"

struct image rotate(struct image source);
struct image rotated_right_90_img (struct image source);
struct image rotated_left_90_img (struct image source);
struct image flipped_vertically_img(struct image source);
struct image flipped_horizontally_img(struct image source);
#endif