#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "vulnerable_parser.h"

#define MAX_INPUT_SIZE 1024
#define OUTPUT_BUFFER_SIZE 64

extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Ensure input is not too large
    if (size > MAX_INPUT_SIZE) {
        return 0;
    }
    
    // Allocate output buffer
    char output[OUTPUT_BUFFER_SIZE];
    
    // Create null-terminated input
    char input[MAX_INPUT_SIZE + 1];
    memcpy(input, data, size);
    input[size] = '\0';
    
    // Call vulnerable function
    int result = parse_untrusted_input(input, output, OUTPUT_BUFFER_SIZE);
    
    // Prevent compiler optimization
    volatile int touched_result = result;
    (void)touched_result;
    
    return 0;
}
