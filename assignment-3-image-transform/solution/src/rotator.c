#include "rotator.h"

struct image rotate(struct image source) {
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

struct image rotated_left_90_img(struct image source) {
    struct image product = create_image(source.height, source.width);

    for (uint64_t i = 0; i < source.height; i++) {
        for (uint64_t j = 0; j < source.width; j++) {
            product.data[j * product.width + (product.width - i - 1)] = source.data[i * source.width + j];
        }
    }

    return product;
}

struct image flipped_vertically_img(struct image source) {
    struct image flipped = create_image(source.width, source.height);

    for (uint64_t i = 0; i < source.height; i++) {
        for (uint64_t j = 0; j < source.width; j++) {
            flipped.data[(source.height - i - 1) * source.width + j] = source.data[i * source.width + j];
        }
    }

    return flipped;
}


struct image flipped_horizontally_img(struct image source) {
    struct image flipped = create_image(source.width, source.height);

    for (uint64_t i = 0; i < source.height; i++) {
        for (uint64_t j = 0; j < source.width; j++) {
            flipped.data[i * source.width + (source.width - j - 1)] = source.data[i * source.width + j];
        }
    }

    return flipped;
}

struct image rotated_right_90_img(struct image source) {
    struct image product = create_image(source.height, source.width);

    for (uint64_t i = 0; i < source.height; i++) {
        for (uint64_t j = 0; j < source.width; j++) {
            product.data[(product.height - j - 1) * product.width + i] = source.data[i * source.width + j];
        }
    }
    return product;
}
