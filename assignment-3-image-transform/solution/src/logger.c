#include "logger.h"

void log_info(int code, const char* argv) {
    switch (code) {
        case 1:
            fprintf(stderr, "ERROR: Invalid number of arguments.\n");
            print_usage(argv);
            break;
        case 2:
            fprintf(stderr, "Error: Failed to read image from '%s'.\n", argv);
            break;
        case 4:
            fprintf(stderr, "Error: Failed to write image to '%s'.\n", argv);
            break;
        default:
            fprintf(stderr, "Unknown error.\n");
    }
}

void log_success() {
    printf("Image transformed successfully.\n");
}

void print_usage(const char *program_name) {
    printf("Usage: %s <source-image> <transformed-image>\n", program_name);
}
