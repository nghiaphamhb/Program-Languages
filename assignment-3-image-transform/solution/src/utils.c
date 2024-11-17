#include "utils.h"

void* allocate_image_memory(size_t size, uint64_t width, uint64_t height){
    if(width == 0 || height == 0) return NULL;
    void* ptr = malloc( size * width * height );
    if(ptr) return ptr; 
    return NULL; 
}

size_t get_padding(const struct image *img){
    return (4 - ((img->width * sizeof(struct pixel)) % 4)) % 4;
}

size_t get_image_size(const struct image *img){
    size_t row_size = img->width * PIXEL_SIZE;
    size_t row_with_padding_size = row_size + get_padding(img);
    return row_with_padding_size * img->height; 
}
