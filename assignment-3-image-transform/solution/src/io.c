#include "io.h"

bool read_header(FILE *in, struct bmp_header *const header){
    if(fread(header, BMP_HEADER_SIZE, 1, in) != 1) return false;
    fseek(in, (long) header->bOffBits, SEEK_SET);
    return true;
}

bool read_data(FILE *in, const struct image *const img){
    size_t padding = get_padding(img);
    struct pixel *first_pixel = img->data;
    for (struct pixel *i_pixel = first_pixel; i_pixel < first_pixel + get_image_size(img); i_pixel += img->width) {
        fread(i_pixel, PIXEL_SIZE, img->width, in);
        fseek(in, (long) padding, SEEK_CUR);
    }
    return true;
}

enum read_status from_bmp(FILE *in, struct image *const img) {
    struct bmp_header header;
    if (!read_header(in, &header)) return READ_INVALID_HEADER;
    if(header.bfType != BMP_TYPE) return READ_INVALID_SIGNATURE;

    *img = create_image(header.biWidth, header.biHeight);
    if (!read_data(in, img)) return READ_INVALID_BITS;

    return READ_OK;
}



bool write_header(FILE* out, const struct image *const img){
    uint32_t image_size = (uint32_t) get_image_size(img);

    struct bmp_header header = {
        .bfType = BMP_TYPE, 
        .bfileSize = BMP_HEADER_SIZE + image_size,
        .bfReserved = BMP_RESERVED, 
        .bOffBits = BMP_HEADER_SIZE, 
        .biSize = DIB_HEADER_SIZE, 
        .biWidth = (uint32_t) img->width,
        .biHeight = (uint32_t) img->height, 
        .biPlanes = BMP_PLANES, 
        .biBitCount = BMP_BITCOUNT, 
        .biCompression = BMP_COMPRESSION_NONE, 
        .biSizeImage = image_size, 
        .biXPelsPerMeter = BMP_DEFAULT_X_PELS_PER_METER,
        .biYPelsPerMeter = BMP_DEFAULT_Y_PELS_PER_METER, 
        .biClrUsed = BMP_COLOR_USED_ALL, 
        .biClrImportant =  BMP_COLOR_IMPORTANT_ALL
    };

    if(out == NULL || (fwrite(&header, BMP_HEADER_SIZE, 1, out) != 1)) return false;
    return true;
}

// bool write_data(FILE* out, const struct image *const img){
//     size_t padding = get_padding(img);

//     for(size_t row_number = 0; row_number < (size_t) img->height; row_number ++){
//         struct pixel first_pixel_in_row = img->data[img->width * row_number];

//         if( fwrite(&first_pixel_in_row, PIXEL_SIZE, img->width, out) != 1) return false;
//         //add padding
//         fseek(out, (long) padding, SEEK_CUR); 
//     }
//     return true;
// }

bool write_data(FILE *out, const struct image *const img) {
    if (!out) {
        printf("Error: Output file is not opened.\n");
        return false;
    }

    size_t padding = get_padding(img);

    for (size_t row_number = 0; row_number < (size_t)img->height; row_number++) {
        struct pixel *first_pixel_in_row = &img->data[img->width * row_number];

        // Ghi hàng pixel
        if (fwrite(first_pixel_in_row, PIXEL_SIZE, img->width, out) != img->width) {
            printf("Error: Failed to write row %zu\n", row_number);
            return false;
        }
        // Ghi padding
        for (size_t i = 0; i < padding; i++) {
            if (fputc(0, out) == EOF) {
                printf("Error: Failed to write padding at row %zu\n", row_number);
                return false;
            }
        }
    }
    return true;
}
enum write_status to_bmp( FILE* out, struct image const* img ){
    if( !write_header(out, img)) return WRITE_ERROR;
    if( !write_data(out, img) ) return WRITE_ERROR;
    return WRITE_OK; 
}