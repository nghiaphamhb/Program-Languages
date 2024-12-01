#ifndef CONFIG 
#define CONFIG

#include "bmp.h"

#define BMP_TYPE 0x4D42

#define BMP_HEADER_SIZE sizeof(struct bmp_header)     
#define DIB_HEADER_SIZE 40        

#define BMP_RESERVED 0            
#define BMP_PLANES 1            
#define BMP_BITCOUNT 24       
#define BMP_COMPRESSION_NONE 0   

#define BMP_DEFAULT_X_PELS_PER_METER 2835 
#define BMP_DEFAULT_Y_PELS_PER_METER 2835 

#define BMP_COLOR_USED_ALL 0     
#define BMP_COLOR_IMPORTANT_ALL 0 

#define PIXEL_SIZE sizeof(struct pixel) 

#endif 


