#include "Primitives.h"
#include <cstdio>   // for snprintf
#include <cstdlib>  // for malloc/free
#include <cstring>  // for strlen/memcpy
#include <limits.h> // for LLONG_MAX, ULLONG_MAX
#include <cerrno>   // for errno (though not strictly needed here, good for C)

// Helper to create a heap-allocated nebula_String_t from a C-style char* buffer.
// This is necessary for Primitives::toString() as the resulting string is usually
// passed out of the scope and must be heap-safe.
nebula_String_t *create_heap_string(const char *c_str)
{
    if (c_str == nullptr)
        return nullptr;

    uint32_t len = (uint32_t)std::strlen(c_str);
    char *data = (char *)std::malloc(len + 1); // +1 for null terminator
    if (data == nullptr)
        return nullptr;

    std::memcpy(data, c_str, len + 1);

    nebula_String_t *new_str = (nebula_String_t *)std::malloc(sizeof(nebula_String_t));
    if (new_str == nullptr)
    {
        std::free(data);
        return nullptr;
    }

    new_str->data = data;
    // NOTE: We cast away const here in Primitives.cpp implementation to handle the memory we allocated.
    // However, the header still uses `const char *data` for the String ABI definition in String.h.
    new_str->length = len;
    return new_str;
}

// Function to correctly destroy a heap-allocated nebula_String_t created by create_heap_string.
// It frees both the internal data buffer and the String object structure itself.
extern "C"
void destroy_heap_string(nebula_String_t *heap_str)
{
    if (heap_str != nullptr)
    {
        // Free the internal data buffer first
        if (heap_str->data != nullptr)
        {
            // Cast away const to free the memory allocated by create_heap_string
            std::free((void*)heap_str->data);
        }
        // Free the String struct itself
        std::free(heap_str);
    }
}


// Function to convert a signed long long to a decimal string using C library
// This replaces std::to_string for signed integers.
// Buffer size 22 is enough for int64_t (max 19 digits + sign + null).
static const char* lltostr(long long val, char* buf) {
    // This uses snprintf to format the number into the provided buffer
    // It's a C-only approach.
    std::snprintf(buf, 22, "%lld", val);
    return buf;
}

// Function to convert an unsigned long long to a decimal string using C library
// This replaces std::to_string for unsigned integers.
// Buffer size 22 is enough for uint64_t (max 20 digits + null).
static const char* ulltostr(unsigned long long val, char* buf) {
    // This uses snprintf to format the number into the provided buffer
    // It's a C-only approach.
    std::snprintf(buf, 22, "%llu", val);
    return buf;
}


extern "C"
{

    // --- Bool ---
    nebula_String_t *nebula_core_Bool_toString__string(bool self)
    {
        return create_heap_string(self ? "true" : "false");
    }

    // --- Integers ---
    // Max buffer size for 64-bit int is 22 (sign + 19 digits + null). We'll use 24 for safety.

    nebula_String_t *nebula_core_Int8_toString__string(int8_t self)
    {
        char buffer[24];
        return create_heap_string(lltostr(self, buffer));
    }

    nebula_String_t *nebula_core_Int16_toString__string(int16_t self)
    {
        char buffer[24];
        return create_heap_string(lltostr(self, buffer));
    }

    nebula_String_t *nebula_core_Int32_toString__string(int32_t self)
    {
        char buffer[24];
        return create_heap_string(lltostr(self, buffer));
    }

    nebula_String_t *nebula_core_Int64_toString__string(int64_t self)
    {
        char buffer[24];
        return create_heap_string(lltostr(self, buffer));
    }

    // --- Unsigned Integers ---

    nebula_String_t *nebula_core_UInt8_toString__string(uint8_t self)
    {
        char buffer[24];
        return create_heap_string(ulltostr(self, buffer));
    }

    nebula_String_t *nebula_core_UInt16_toString__string(uint16_t self)
    {
        char buffer[24];
        return create_heap_string(ulltostr(self, buffer));
    }

    nebula_String_t *nebula_core_UInt32_toString__string(uint32_t self)
    {
        char buffer[24];
        return create_heap_string(ulltostr(self, buffer));
    }

    nebula_String_t *nebula_core_UInt64_toString__string(uint64_t self)
    {
        char buffer[24];
        return create_heap_string(ulltostr(self, buffer));
    }

    // --- Floating Point ---

    nebula_String_t *nebula_core_Float_toString__string(float self)
    {
        // Max buffer size for float is 32.
        char buffer[32];
        // Use snprintf for precise float formatting (C standard library)
        std::snprintf(buffer, sizeof(buffer), "%.6g", self);
        return create_heap_string(buffer);
    }

    nebula_String_t *nebula_core_Double_toString__string(double self)
    {
        // Max buffer size for double is 64.
        char buffer[64];
        std::snprintf(buffer, sizeof(buffer), "%.15g", self);
        return create_heap_string(buffer);
    }

    // --- Character ---

    nebula_String_t *nebula_core_Char_toString__string(char self)
    {
        char buffer[2];
        buffer[0] = self;
        buffer[1] = '\0';
        return create_heap_string(buffer);
    }

} // extern "C"
