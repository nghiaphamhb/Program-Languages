#ifndef CONFIG 
#define CONFIG

#include "bmp.h"

#define BMP_TYPE 0x4D42

#define BMP_HEADER_SIZE sizeof(struct bmp_header)       // Kích thước tối thiểu của toàn bộ header BMP
#define DIB_HEADER_SIZE 40        // Kích thước thông tin header (BITMAPINFOHEADER)

#define BMP_RESERVED 0            // Trường dự trữ, luôn là 0
#define BMP_PLANES 1              // Số mặt phẳng (luôn là 1 cho BMP)
#define BMP_BITCOUNT 24        // Số bit trên mỗi pixel (24 bit cho ảnh màu không nén)
#define BMP_COMPRESSION_NONE 0    // Không nén

#define BMP_DEFAULT_X_PELS_PER_METER 2835 // Tương đương khoảng 72 DPI
#define BMP_DEFAULT_Y_PELS_PER_METER 2835 // Tương đương khoảng 72 DPI

#define BMP_COLOR_USED_ALL 0     
#define BMP_COLOR_IMPORTANT_ALL 0 

#define PIXEL_SIZE sizeof(struct pixel) 

#endif 


