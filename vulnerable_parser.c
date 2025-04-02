// vulnerable_parser.c
#include <string.h>
#include <stdlib.h>
#include "vulnerable_parser.h"

int parse_untrusted_input(const char* input, char* output, int output_size) {
    // Vulnerability 1: No input length validation
    // Vulnerability 2: Potential buffer overflow
    // Vulnerability 3: Unsafe memory operations
    
    // Copy input to output without checking length
    // This will cause buffer overflow for inputs longer than output_size
    strcpy(output, input);
    
    // Additional unsafe operations to increase crash potential
    int input_len = strlen(input);
    
    // Arbitrary computation to make the function do something
    int checksum = 0;
    for (int i = 0; i < input_len; i++) {
        // Potential integer overflow
        checksum += (unsigned char)input[i] * (i + 1);
    }
    
    // Intentionally unsafe pointer arithmetic
    char* dangerous_ptr = output + input_len;
    *dangerous_ptr = '\0';  // Potential out-of-bounds write
    
    return checksum;
}
