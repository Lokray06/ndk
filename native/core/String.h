#ifndef STRING_H
#define STRING_H

#include <stdint.h>

// -------------------------------------------------------------------
// NDK String ABI Layout (Crucial for LLVM Codegen)
// This must EXACTLY match the memory layout of the C++ implementation!
// -------------------------------------------------------------------
typedef struct
{
    // 1. Pointer to the raw UTF-8 data (points to the global LLVM string constant).
    const char *data;

    // 2. Length field.
    uint32_t length;
} nebula_String_t;

// typedef nebula_String_t string;

#endif
