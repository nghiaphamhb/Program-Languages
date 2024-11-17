#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h" 
#include "logger.h" 
#include "io.h" 


int main(int argc, char *argv[]) {
    // Kiểm tra số lượng tham số
    if (argc != 4) {
        const char *name_program = argv[0];
        log_info(1, name_program);
        return;
    }

    const char *source_image_path = argv[1];
    const char *transformed_image_path = argv[2];
    const char *transformation = argv[3];

    // Đọc ảnh từ file nguồn
    struct image *source_image = (struct image*)malloc(sizeof(struct image));

    if (from_bmp(source_image_path, &source_image) != READ_OK) {
        log_info(2, source_image_path);
        return;
    }

    // Tạo biến ảnh đích
    struct image *transformed_image = (struct image*)malloc(sizeof(struct image));

    // Thực hiện phép biến đổi
    if (strcmp(transformation, "cw90") == 0 || 
        strcmp(transformation, "ccw90") == 0 || 
        strcmp(transformation, "fliph") == 0 || 
        strcmp(transformation, "flipv") == 0 || 
        strcmp(transformation, "none") == 0) {
        transformed_image = rotate(source_image, transformation);
    } else {
        log_info(3, transformation);
        destroy_image(source_image); // Giải phóng bộ nhớ của ảnh nguồn
    return;
}

    

    // Ghi ảnh đã biến đổi ra file đích
    if (to_bmp(transformed_image_path, &transformed_image) != WRITE_OK) {
        log_info(4, transformed_image_path);
        destroy_image(source_image);
        destroy_image(transformed_image);
        return ;
    }

    // Giải phóng bộ nhớ
    destroy_image(source_image);
    destroy_image(transformed_image);

    log_success();
    return 1;
}
