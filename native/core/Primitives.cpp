#include "Primitives.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

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
    new_str->length = len;
    return new_str;
}

extern "C"
{

    // --- Bool ---
    nebula_String_t *nebula_core_Bool_toString__string(bool self)
    {
        return create_heap_string(self ? "true" : "false");
    }

    // --- Integers ---

    nebula_String_t *nebula_core_Int8_toString__string(int8_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_Int16_toString__string(int16_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_Int32_toString__string(int32_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_Int64_toString__string(int64_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    // --- Unsigned Integers ---

    nebula_String_t *nebula_core_UInt8_toString__string(uint8_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_UInt16_toString__string(uint16_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_UInt32_toString__string(uint32_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    nebula_String_t *nebula_core_UInt64_toString__string(uint64_t self)
    {
        std::string s = std::to_string(self);
        return create_heap_string(s.c_str());
    }

    // --- Floating Point ---

    nebula_String_t *nebula_core_Float_toString__string(float self)
    {
        // Use snprintf for precise float formatting
        char buffer[32];
        std::snprintf(buffer, sizeof(buffer), "%.6g", self);
        return create_heap_string(buffer);
    }

    nebula_String_t *nebula_core_Double_toString__string(double self)
    {
        char buffer[32];
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
