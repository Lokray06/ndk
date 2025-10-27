#ifndef NEBULA_ARRAY_H
#define NEBULA_ARRAY_H

#include <stdint.h> // For uint32_t

// -------------------------------------------------------------------
// NDK Array ABI Layout
// Represents a reference to fixed-size array data.
// The actual array data [Size x ElementType] is stored elsewhere.
// -------------------------------------------------------------------
typedef struct
{
    // 1. Pointer to the raw array data (e.g., void*).
    //    Codegen will cast this based on the actual element type.
    void* data;

    // 2. The fixed size (number of elements) of the array.
    uint32_t size;

} nebula_Array_t;


#endif // NEBULA_ARRAY_H
