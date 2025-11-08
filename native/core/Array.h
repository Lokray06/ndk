#ifndef NEBULA_ARRAY_H
#define NEBULA_ARRAY_H

#include <stdint.h> // For uint32_t

// -------------------------------------------------------------------
// NDK Array ABI Layout
// Represents a reference to fixed-size array data.
// The actual array data [Size x ElementType] is stored elsewhere.
//
// This struct is the C++ equivalent of what the compiler
// allocates and manages in IRVisitor.java
// -------------------------------------------------------------------
typedef struct
{
    // 1. Pointer to the raw array data (e.g., void*).
    //    Codegen will cast this based on the actual element type.
    void* data;

    // 2. The fixed size (number of elements) of the array.
    uint32_t size;

} nebula_Array_t;


// -------------------------------------------------------------------
// C++ Declarations for native methods in core/Array.neb
//
// Mangling Scheme:
//   fully_qualified_name__paramType1__paramType2___returnType
//
// NOTE: elementAt and setElementAt are handled as "intrinsics"
// by the compiler (IRVisitor) and do not have C++ implementations.
// Only the 'length' property getter is implemented in C++.
// -------------------------------------------------------------------

extern "C" {

    /**
     * Native implementation for: native public int length; (GET)
     * Mangled name for: nebula_core_Array_get_length___int
     */
    int32_t nebula_core_Array_get_length___int(nebula_Array_t* self);

}


#endif // NEBULA_ARRAY_H