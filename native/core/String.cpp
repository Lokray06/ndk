#include "String.h"
#include <iostream>
#include <cstring>

// This file implements the native methods for the nebula.core.String class.

extern "C"
{

    // NOTE: The heap-allocating function nebula_String_t_t_literal_create is REMOVED.
    // LLVM now handles stack allocation directly.

    // ----------------------
    // Implementations of native methods from core/String.neb
    // ----------------------

    // native public char charAt(int index);
    char nebula_core_String_charAt__int__char(const nebula_String_t *self, int index)
    {
        if (index < 0 || (uint32_t)index >= self->length)
        {
            // Runtime Error handling here
            std::cerr << "Runtime Error: String index out of bounds (" << index << ")." << std::endl;
            return 0;
        }
        return self->data[index];
    }

    // native public bool equals(string other);
    bool nebula_core_String_equals__string__bool(const nebula_String_t *self, const nebula_String_t *other)
    {
        if (self == other)
            return true;
        if (self->length != other->length)
            return false;
        return std::memcmp(self->data, other->data, self->length) == 0;
    }

    // native public string toString();
    nebula_String_t *nebula_core_String_toString__string(nebula_String_t *self)
    {
        // Since this is a stack-allocated literal, returning its address is safe
        // within the current scope, and no heap operation is needed.
        return self;
    }

    // Internal function used by Console.cpp
    void string_print(const nebula_String_t *s)
    {
        if (s && s->data)
        {
            // Output the data using the length field
            std::cout.write(s->data, s->length);
        }
    }

} // extern "C"
