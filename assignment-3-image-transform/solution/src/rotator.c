#include "rotator.h"

struct image* rotate(struct image* source) {
    char* transformation = "";
    if (strcmp(transformation, "cw90") == 0) {
        return rotated_right_90_img(source);  
    } else if (strcmp(transformation, "") == 0) { //ccw90 
        return rotated_left_90_img(source);   
    } else if (strcmp(transformation, "fliph") == 0) {
        return flipped_horizontally_img(source);
    } else if (strcmp(transformation, "flipv") == 0) {
        return flipped_vertically_img(source); 
    } else {
        return source;
    }
}

struct image* rotated_left_90_img(  struct image* source) {
    struct image* product = (struct image*)malloc(sizeof(struct image)); 
    if (product == NULL) {
        return NULL; 
    }

    product->width = source->height;
    product->height = source->width;

    product->data = (struct pixel*)allocate_image_memory(PIXEL_SIZE, product->width, product->height);
    if (product->data == NULL) {
        free(product);  
        return NULL;
    }
    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            product->data[j * product->width + (product->width - i - 1)] = source->data[i * source->width + j];
        }
    }
    return product;  
}


struct image* flipped_vertically_img( struct image* source) {
    struct image* flipped = (struct image*)malloc(sizeof(struct image));  
    if (flipped == NULL) {
        return NULL;  
    }

    flipped->width = source->width;
    flipped->height = source->height;

    flipped->data = (struct pixel*)malloc(flipped->width * flipped->height * sizeof(struct pixel));
    if (flipped->data == NULL) {
        free(flipped); 
        return NULL;
    }

    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            flipped->data[(source->height - i - 1) * source->width + j] = source->data[i * source->width + j];
        }
    }

    return flipped; 
}

struct image* flipped_horizontally_img( struct image* source) {
    struct image* flipped = (struct image*)malloc(sizeof(struct image));  
    if (flipped == NULL) {
        return NULL;  
    }

    flipped->width = source->width;
    flipped->height = source->height;

    flipped->data = (struct pixel*)malloc(flipped->width * flipped->height * sizeof(struct pixel));
    if (flipped->data == NULL) {
        free(flipped);  
        return NULL;
    }

    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            flipped->data[i * source->width + (source->width - j - 1)] = source->data[i * source->width + j];
        }
    }

    return flipped; 
}


struct image* rotated_right_90_img( struct image* source) {
    struct image* product = (struct image*)malloc(sizeof(struct image));  
    if (product == NULL) {
        return NULL;  
    }

    product->width = source->height;
    product->height = source->width;

    product->data = (struct pixel*)allocate_image_memory(PIXEL_SIZE, product->width, product->height);

    if (product->data == NULL) {
        free(product);  
        return NULL;
    }

    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            product->data[(product->height - j - 1) * product->width + i] = source->data[i * source->width + j];
        }
    }

    return product;  
}