#include "image.h"

struct image create_image(uint64_t width, uint64_t height){
    struct pixel* data = ALLOCATE_IMAGE_MEMORY(struct pixel, width, height);
    return (struct image) {.width = width, .height = height, .data = data};
}

void destroy_image(const struct image image) {
    free(image.data); 
}

size_t get_padding(const struct image *img){
    return (4 - ((img->width * sizeof(struct pixel)) % 4)) % 4;
}

size_t get_image_size(const struct image *img){
    size_t row_size = img->width * PIXEL_SIZE;
    size_t row_with_padding_size = row_size + get_padding(img);
    return row_with_padding_size * img->height; 
}
