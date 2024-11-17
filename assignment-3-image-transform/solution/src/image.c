
#include "image.h"
#include "utils.h"

struct image create_image(uint64_t width, uint64_t height){
    struct pixel* data = ALLOCATE_IMAGE_MEMORY(struct pixel, width, height);
    return (struct image) {.width = width, .height = height, .data = data};
}

void destroy_image(struct image* image){
    free(image->data);
}

size_t image_size(struct image* img) {
    return (size_t)(img->width * img->height);
}

// struct image {
//   uint64_t width, height;
//   struct pixel* data;
// };