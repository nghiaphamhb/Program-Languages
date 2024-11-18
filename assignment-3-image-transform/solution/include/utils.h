#ifndef UTILS
#define UTILS

#include <stdint.h>
#include <stdlib.h>
#include "image.h"
#include "config.h"

#define ALLOCATE_IMAGE_MEMORY(type, width, height) \
(type*) allocate_image_memory(sizeof(type), width, height)

void* allocate_image_memory(size_t size, uint64_t width, uint64_t height);




#endif 