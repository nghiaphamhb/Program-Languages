#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h" 
#include "logger.h" 
#include "io.h" 
#include "rotator.h" 


int main(int argc, char *argv[]) {
    if (argc != 4) {
        const char *name_program = argv[0];
        log_info(1, name_program);
        return 1;
    }

    const char *source_image_path = argv[1];
    const char *transformed_image_path = argv[2];
    const char *transformation = argv[3];

    FILE *file_in = fopen(source_image_path, "rb"); 
        if (!file_in) { 
        log_info(2, "Could not open file input.");
        return 1;
    }

    struct image *source_image = (struct image*)malloc(sizeof(struct image));

    if (from_bmp(file_in, source_image) != READ_OK) {
        log_info(2, source_image_path);
        return 1;
    }

    struct image *transformed_image = (struct image*)malloc(sizeof(struct image));

    if (strcmp(transformation, "cw90") == 0 || 
        strcmp(transformation, "ccw90") == 0 || 
        strcmp(transformation, "fliph") == 0 || 
        strcmp(transformation, "flipv") == 0 || 
        strcmp(transformation, "none") == 0) {
        transformed_image = rotate(source_image, transformation);
    } else {
        log_info(3, transformation);
        destroy_image(source_image); 
    return 1;
}

    FILE *file_out = fopen(transformed_image_path, "wb"); 
        if (!file_out) { 
        log_info(2, "Could not open file output.");
        return 1;
    }

    if (to_bmp(file_out, transformed_image) != WRITE_OK) {
        log_info(4, transformed_image_path);
        destroy_image(source_image);
        destroy_image(transformed_image);
        return 1;
    }

    destroy_image(source_image);
    destroy_image(transformed_image);

    log_success();
    return 0;
}
