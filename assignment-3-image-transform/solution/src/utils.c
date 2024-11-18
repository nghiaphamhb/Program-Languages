#include "utils.h"

void* allocate_image_memory(size_t size, uint64_t width, uint64_t height){
    if(width == 0 || height == 0) return NULL;
    void* ptr = malloc( size * width * height );
    if(ptr) return ptr; 
    return NULL; 
}

