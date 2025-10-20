#ifndef CONSOLE_H
#define CONSOLE_H

#include "../Primitives.h" // For String and mstring ABI
#include "../String.h" // For String and mstring ABI

extern "C" {

// --- Print Methods ---
void nebula_core_io_Console_print__Object___void(void* anything); // Object is always passed as a generic pointer
void nebula_core_io_Console_print__bool__void(bool boolean);
void nebula_core_io_Console_print__char__void(char character);
void nebula_core_io_Console_print__string__void(const string* anyString);
void nebula_core_io_Console_print__byte__void(int8_t number);
void nebula_core_io_Console_print__short__void(int16_t number);
void nebula_core_io_Console_print__int__void(int32_t number);
void nebula_core_io_Console_print__long__void(int64_t number);
void nebula_core_io_Console_print__float__void(float number);
void nebula_core_io_Console_print__double__void(double number);

// --- Println Methods ---
void nebula_core_io_Console_println__void();
void nebula_core_io_Console_println__Object___void(void* anything);
void nebula_core_io_Console_println__bool__void(bool boolean);
void nebula_core_io_Console_println__char__void(char character);
void nebula_core_io_Console_println__string___void(const string* anyString);
void nebula_core_io_Console_println__byte__void(int8_t number);
void nebula_core_io_Console_println__short__void(int16_t number);
void nebula_core_io_Console_println__int__void(int32_t number);
void nebula_core_io_Console_println__long__void(int64_t number);
void nebula_core_io_Console_println__float__void(float number);
void nebula_core_io_Console_println__double__void(double number);

/*
// --- Input Methods ---
string* nebula_core_io_Console_readLine__string();
*/

// Internal Print Utility (must be defined in String.cpp/h or elsewhere)
extern void string_print(const string* s);

}

#endif // NDK_CONSOLE_H
