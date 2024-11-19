#ifndef BMP
#define BMP

#include <stdint.h>

// Đảm bảo không có khoảng cách giữa các trường trong cấu trúc
#pragma pack(push, 1)
struct bmp_header {
    uint16_t bfType;             // Kiểu tệp (0x4D42 cho BMP, "BM")
    uint32_t bfileSize;          // Kích thước của tệp BMP (bao gồm header + dữ liệu ảnh)
    uint32_t bfReserved;         // Dữ liệu dự trữ, thường là 0
    uint32_t bOffBits;           // Offset, vị trí bắt đầu của dữ liệu ảnh trong tệp
    uint32_t biSize;             // Kích thước của thông tin header (thường là 40)
    uint32_t biWidth;            // Chiều rộng của hình ảnh (tính theo pixel)
    uint32_t biHeight;           // Chiều cao của hình ảnh (tính theo pixel)
    uint16_t biPlanes;           // Số mặt phẳng (luôn là 1 cho BMP)
    uint16_t biBitCount;         // Số bit trên mỗi pixel (ví dụ: 24 bit cho ảnh màu)
    uint32_t biCompression;      // Kiểu nén (0 là không nén, 1 là nén RLE)
    uint32_t biSizeImage;        // Kích thước dữ liệu hình ảnh (không bao gồm header)
    uint32_t biXPelsPerMeter;    // Số pixel trên mỗi mét (chỉ số phân giải ngang)
    uint32_t biYPelsPerMeter;    // Số pixel trên mỗi mét (chỉ số phân giải dọc)
    uint32_t biClrUsed;          // Số màu thực sự sử dụng trong hình ảnh (0 nếu sử dụng tất cả màu)
    uint32_t biClrImportant;     // Số màu quan trọng (0 nếu tất cả đều quan trọng)
};

struct pixel {
    uint8_t b, g, r;  // Lưu trữ màu sắc của pixel dưới dạng Blue, Green, Red (24-bit)
};
#pragma pack(pop)

#endif
