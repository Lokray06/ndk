#include "Array.h"
#include <unistd.h> // For write
#include <cstdio>   // For snprintf
#include <cstdlib>  // For exit
#include <cstring>  // For strlen

/**
 * @brief Helper function to report a fatal runtime error and exit.
 */
static void runtime_error(const char* message) {
    write(2, message, strlen(message)); // Write to stderr
    write(2, "\n", 1);
    exit(1); // Exit with error
}

extern "C" {

    // --- Length Property Getter ---

    /**
     * Native implementation for: native public int length; (GET)
     * Mangled name: nebula_core_Array_get_length___int
     */
    int32_t nebula_core_Array_get_length___int(nebula_Array_t* self) {
        if (!self) {
             runtime_error("Runtime Error: Cannot read length of null array.");
        }
        return self->size;
    }

}