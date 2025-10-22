#include "Console.h"
#include "../Primitives.h" // Needed for toString() and destroy_heap_string()
#include <unistd.h> // For write
#include <cstdio>   // For snprintf
#include <cstdint>  // For intX_t types

// We must assume the 'string' type and 'string_print' function
// are defined elsewhere (via Console.h -> String.h)
extern "C" void string_print(const nebula_String_t *s);


extern "C"
{
    // --- Print Utilities: Use toString() and then string_print() ---

    void nebula_core_io_Console_print__bool___void(bool boolean)
    {
        // Use Bool::toString()
        nebula_String_t *s = nebula_core_Bool_toString__string(boolean);
        nebula_core_io_Console_print__string___void(s);
        // Clean up the temporary string object
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__char___void(char character)
    {
        // Use Char::toString()
        nebula_String_t *s = nebula_core_Char_toString__string(character);
        nebula_core_io_Console_print__string___void(s);
        // Clean up the temporary string object
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__string___void(const nebula_String_t *anyString)
    {
        // This function delegates to the internal low-level write function (string_print).
        string_print(anyString);
    }

    void nebula_core_io_Console_print__byte___void(int8_t number)
    {
        // Use Int8::toString()
        nebula_String_t *s = nebula_core_Int8_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__short___void(int16_t number)
    {
        // Use Int16::toString()
        nebula_String_t *s = nebula_core_Int16_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__int___void(int32_t number)
    {
        // Use Int32::toString()
        nebula_String_t *s = nebula_core_Int32_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__long___void(int64_t number)
    {
        // Use Int64::toString()
        nebula_String_t *s = nebula_core_Int64_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    // --- Unsigned Print Utilities ---

    void nebula_core_io_Console_print__ubyte___void(uint8_t number)
    {
        // Use UInt8::toString()
        nebula_String_t *s = nebula_core_UInt8_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__ushort___void(uint16_t number)
    {
        // Use UInt16::toString()
        nebula_String_t *s = nebula_core_UInt16_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__uint___void(uint32_t number)
    {
        // Use UInt32::toString()
        nebula_String_t *s = nebula_core_UInt32_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__ulong___void(uint64_t number)
    {
        // Use UInt64::toString()
        nebula_String_t *s = nebula_core_UInt64_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    // Floating point types use C library for controlled output
    void nebula_core_io_Console_print__float___void(float number)
    {
        // Use Float::toString()
        nebula_String_t *s = nebula_core_Float_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    void nebula_core_io_Console_print__double___void(double number)
    {
        // Use Double::toString()
        nebula_String_t *s = nebula_core_Double_toString__string(number);
        nebula_core_io_Console_print__string___void(s);
        destroy_heap_string(s);
    }

    // Object printing (pointer address)
    void nebula_core_io_Console_print__Object___void(void *anything)
    {
        if (anything == nullptr)
        {
            write(1, "null", 4);
        }
        else
        {
            // NOTE: Object::toString() would be ideal here, but since the
            // Object class isn't fully defined yet, we keep the raw pointer
            // printing logic for safety.
            char buf[64]; // Buffer for pointer address
            int len = snprintf(buf, sizeof(buf), "@%p", anything); // Print address
            if (len > 0) {
                write(1, buf, len);
            }
        }
    }

    // --- Println Methods (add newline after printing) ---

    void nebula_core_io_Console_println___void()
    {
        // This function already correctly uses write
        write(1, "\n", 1);
    }

    // The println overloads simply call the print overloads and then print a newline.

    void nebula_core_io_Console_println__Object___void(void *anything)
    {
        nebula_core_io_Console_print__Object___void(anything);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__bool___void(bool boolean)
    {
        nebula_core_io_Console_print__bool___void(boolean);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__char___void(char character)
    {
        nebula_core_io_Console_print__char___void(character);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__string___void(const nebula_String_t *anyString)
    {
        nebula_core_io_Console_print__string___void(anyString);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__byte___void(int8_t number)
    {
        nebula_core_io_Console_print__byte___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__short___void(int16_t number)
    {
        nebula_core_io_Console_print__short___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__int___void(int32_t number)
    {
        nebula_core_io_Console_print__int___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__long___void(int64_t number)
    {
        nebula_core_io_Console_print__long___void(number);
        nebula_core_io_Console_println___void();
    }

    // --- Unsigned Println Methods ---

    void nebula_core_io_Console_println__ubyte___void(uint8_t number)
    {
        nebula_core_io_Console_print__ubyte___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__ushort___void(uint16_t number)
    {
        nebula_core_io_Console_print__ushort___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__uint___void(uint32_t number)
    {
        nebula_core_io_Console_print__uint___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__ulong___void(uint64_t number)
    {
        nebula_core_io_Console_print__ulong___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__float___void(float number)
    {
        nebula_core_io_Console_print__float___void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__double___void(double number)
    {
        nebula_core_io_Console_print__double___void(number);
        nebula_core_io_Console_println___void();
    }
    /*

    // --- Input Methods ---
    // (This section remains commented as it requires standard C++ I/O which might be undesirable)

    // NOTE: For now, we assume create_heap_string is available via linking.
    // extern string *create_heap_string(const char *c_str);

    // string *nebula_core_io_Console_readLine__string()
    // {
    //     std::string line;
    //     if (std::getline(std::cin, line))
    //     {
    //         return create_heap_string(line.c_str());
    //     }
    //     return create_heap_string("");
    // }
    */

} // extern "C"