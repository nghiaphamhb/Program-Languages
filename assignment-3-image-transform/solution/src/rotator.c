#include "rotator.h"


//quay 90 do ? 
struct image* rotate(struct image* source, const char* transformation) {
    if (strcmp(transformation, "cw90") == 0) {
        return rotated_right_90_img(source);  // Trả về con trỏ sau khi xoay phải 90 độ
    } else if (strcmp(transformation, "ccw90") == 0) {
        return rotated_left_90_img(source);   // Trả về con trỏ sau khi xoay trái 90 độ
    } else if (strcmp(transformation, "fliph") == 0) {
        return flipped_horizontally_img(source); // Trả về con trỏ sau khi lật ngang
    } else if (strcmp(transformation, "flipv") == 0) {
        return flipped_vertically_img(source); // Trả về con trỏ sau khi lật dọc
    } else {
        // Nếu không có phép biến đổi hợp lệ, trả về con trỏ ảnh gốc
        return source;
    }
}


struct image* rotated_right_90_img( struct image* source) {
    // Cấp phát bộ nhớ cho đối tượng `product`
    struct image* product = (struct image*)malloc(sizeof(struct image));  // Cấp phát bộ nhớ cho struct image
    if (product == NULL) {
        return NULL;  // Trả về NULL nếu không thể cấp phát bộ nhớ
    }

    // Cập nhật thông tin về kích thước của ảnh sau khi quay
    product->width = source->height;
    product->height = source->width;

    // Cấp phát bộ nhớ cho dữ liệu của ảnh mới
    product->data = (struct pixel*)allocate_image_memory(PIXEL_SIZE, product->width, product->height);

    if (product->data == NULL) {
        free(product);  // Giải phóng bộ nhớ của product nếu không thể cấp phát bộ nhớ cho data
        return NULL;
    }

    // Quay ảnh 90 độ sang phải
    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            // Lấy pixel từ ảnh cũ và đặt vào ảnh mới
            product->data[(product->height - j - 1) * product->width + i] = source->data[i * source->width + j];
        }
    }

    return product;  
}


struct image* rotated_left_90_img(  struct image* source) {
    // Cấp phát bộ nhớ cho đối tượng product
    struct image* product = (struct image*)malloc(sizeof(struct image)); 
    if (product == NULL) {
        return NULL; // Trả về NULL nếu không thể cấp phát bộ nhớ
    }

    product->width = source->height;
    product->height = source->width;

    // Cấp phát bộ nhớ cho dữ liệu của ảnh mới
    product->data = (struct pixel*)allocate_image_memory(PIXEL_SIZE, product->width, product->height);
    if (product->data == NULL) {
        free(product);  // Giải phóng bộ nhớ của product nếu không thể cấp phát bộ nhớ cho data
        return NULL;
    }

    // Quay ảnh 90 độ sang trái
    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            // Ánh xạ pixel từ ảnh cũ sang ảnh mới
            product->data[j * product->width + (product->width - i - 1)] = source->data[i * source->width + j];
        }
    }

    return product;  // Trả về con trỏ đến ảnh đã quay
}


struct image* flipped_vertically_img( struct image* source) {
    // Cấp phát bộ nhớ cho đối tượng flipped
    struct image* flipped = (struct image*)malloc(sizeof(struct image));  
    if (flipped == NULL) {
        return NULL;  // Trả về NULL nếu không thể cấp phát bộ nhớ
    }

    flipped->width = source->width;
    flipped->height = source->height;

    // Cấp phát bộ nhớ cho dữ liệu của ảnh mới
    flipped->data = (struct pixel*)malloc(flipped->width * flipped->height * sizeof(struct pixel));
    if (flipped->data == NULL) {
        free(flipped);  // Giải phóng bộ nhớ của flipped nếu không thể cấp phát bộ nhớ cho data
        return NULL;
    }

    // Lật dọc
    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            flipped->data[(source->height - i - 1) * source->width + j] = source->data[i * source->width + j];
        }
    }

    return flipped;  // Trả về con trỏ đến ảnh đã lật dọc
}

struct image* flipped_horizontally_img( struct image* source) {
    // Cấp phát bộ nhớ cho đối tượng flipped
    struct image* flipped = (struct image*)malloc(sizeof(struct image));  
    if (flipped == NULL) {
        return NULL;  // Trả về NULL nếu không thể cấp phát bộ nhớ
    }

    flipped->width = source->width;
    flipped->height = source->height;

    // Cấp phát bộ nhớ cho dữ liệu của ảnh mới
    flipped->data = (struct pixel*)malloc(flipped->width * flipped->height * sizeof(struct pixel));
    if (flipped->data == NULL) {
        free(flipped);  // Giải phóng bộ nhớ của flipped nếu không thể cấp phát bộ nhớ cho data
        return NULL;
    }

    // Lật ngang
    for (uint64_t i = 0; i < source->height; i++) {
        for (uint64_t j = 0; j < source->width; j++) {
            flipped->data[i * source->width + (source->width - j - 1)] = source->data[i * source->width + j];
        }
    }

    return flipped;  // Trả về con trỏ đến ảnh đã lật ngang
}



