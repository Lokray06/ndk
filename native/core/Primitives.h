#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <stdint.h>
#include "String.h" // Includes nebula_String_t

extern "C"
{

// Helper for cleaning up heap-allocated strings returned by toString methods.
// Must be called after using the string pointer in temporary contexts.
void destroy_heap_string(nebula_String_t *heap_str);

// --- Bool ---
nebula_String_t* nebula_core_Bool_toString__string(bool self);

// --- Signed Integers ---
nebula_String_t* nebula_core_Int8_toString__string(int8_t self);
nebula_String_t* nebula_core_Int16_toString__string(int16_t self);
nebula_String_t* nebula_core_Int32_toString__string(int32_t self);
nebula_String_t* nebula_core_Int64_toString__string(int64_t self);

// --- Unsigned Integers ---
nebula_String_t* nebula_core_UInt8_toString__string(uint8_t self);
nebula_String_t* nebula_core_UInt16_toString__string(uint16_t self);
nebula_String_t* nebula_core_UInt32_toString__string(uint32_t self);
nebula_String_t* nebula_core_UInt64_toString__string(uint64_t self);

// --- Floating Point ---
nebula_String_t* nebula_core_Float_toString__string(float self);
nebula_String_t* nebula_core_Double_toString__string(double self);

// --- Character ---
nebula_String_t* nebula_core_Char_toString__string(char self);

}

#endif // NDK_PRIMITIVES_H
