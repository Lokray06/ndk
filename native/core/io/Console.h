#ifndef CONSOLE_H
#define CONSOLE_H

#include "../Primitives.h" // For String and mstring ABI
#include "../String.h" // For String and mstring ABI

extern "C" {

// --- Print Methods ---
void nebula_core_io_Console_print__Object___void(void* anything); // Object is always passed as a generic pointer
void nebula_core_io_Console_print__bool___void(bool boolean);
void nebula_core_io_Console_print__char___void(char character);
void nebula_core_io_Console_print__string___void(const nebula_String_t* anyString);
void nebula_core_io_Console_print__byte___void(int8_t number);
void nebula_core_io_Console_print__short___void(int16_t number);
void nebula_core_io_Console_print__int___void(int32_t number);
void nebula_core_io_Console_print__long___void(int64_t number);
void nebula_core_io_Console_print__float___void(float number);
void nebula_core_io_Console_print__double___void(double number);

// --- Println Methods ---
void nebula_core_io_Console_println___void();
void nebula_core_io_Console_println__Object___void(void* anything);
void nebula_core_io_Console_println__bool___void(bool boolean);
void nebula_core_io_Console_println__char___void(char character);
void nebula_core_io_Console_println__string___void(const nebula_String_t* anyString);
void nebula_core_io_Console_println__byte___void(int8_t number);
void nebula_core_io_Console_println__short___void(int16_t number);
void nebula_core_io_Console_println__int___void(int32_t number);
void nebula_core_io_Console_println__long___void(int64_t number);
void nebula_core_io_Console_println__float___void(float number);
void nebula_core_io_Console_println__double___void(double number);

/*
// --- Input Methods ---
string* nebula_core_io_Console_readLine__string();
*/

// Internal Print Utility (must be defined in String.cpp/h or elsewhere)
extern void string_print(const nebula_String_t* s);

}

#endif // NDK_CONSOLE_H
