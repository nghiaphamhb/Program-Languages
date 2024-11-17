#ifndef UTILS
#define UTILS

#define ALLOCATE_IMAGE_MEMORY(type, width, height) \
(type*) allocate_image_memory(sizeof(type), width, height)

void* allocate_image_memory(size_t size, uint64_t width, uint64_t height);

size_t get_padding(const struct image *img);
size_t get_image_size(const struct image *img);


//ko can dung toi 
void check_allocation(void* ptr);
void swap(int* a, int* b);  // Dùng cho các thao tác đổi giá trị, ví dụ xoay tọa độ
#endif 