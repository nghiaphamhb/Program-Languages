#include "image.h"


struct image create_image(uint64_t width, uint64_t height){
    struct pixel* data = ALLOCATE_IMAGE_MEMORY(struct pixel, width, height);
    return (struct image) {.width = width, .height = height, .data = data};
}

void destroy_image(struct image* image) {
    if (image != NULL && image->data != NULL) {
        free(image->data);  
        image->data = NULL;  
    }
}


// struct image {
//   uint64_t width, height;
//   struct pixel* data;
// };