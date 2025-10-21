#include "Console.h"
#include <unistd.h> // For write
#include <cstdio>   // For snprintf
#include <cstdint>  // For intX_t types
// <iostream> and <string> are no longer needed for output

// We must assume the 'string' type and 'string_print' function
// are defined elsewhere (via Console.h -> String.h)
extern "C" void string_print(const nebula_String_t *s);


extern "C"
{
    // Internal function to print a nebula_String_t (defined in String.cpp)
    //  extern void string_print(const nebula_String_t *s);
    // --- Print Utilities: Use write() and snprintf() for formatting ---

    void nebula_core_io_Console_print__bool__void(bool boolean)
    {
        if (boolean) {
            // Write "true" to stdout
            write(1, "true", 4);
        } else {
            // Write "false" to stdout
            write(1, "false", 5);
        }
    }

    void nebula_core_io_Console_print__char__void(char character)
    {
        // Write the single character byte to stdout
        write(1, &character, 1);
    }

    void nebula_core_io_Console_print__string__void(const nebula_String_t *anyString)
    {
        // This function's implementation is external. We assume string_print
        // correctly handles its own output (hopefully using write).
        string_print(anyString);
    }

    // All integer types are converted to string using snprintf
    void nebula_core_io_Console_print__byte__void(int8_t number)
    {
        char buf[16]; // Buffer for 8-bit int string
        // Cast to int for snprintf %d formatter
        int len = snprintf(buf, sizeof(buf), "%d", static_cast<int>(number));
        if (len > 0) {
            write(1, buf, len);
        }
    }

    void nebula_core_io_Console_print__short__void(int16_t number)
    {
        char buf[16]; // Buffer for 16-bit int string
        int len = snprintf(buf, sizeof(buf), "%d", number);
        if (len > 0) {
            write(1, buf, len);
        }
    }

    void nebula_core_io_Console_print__int__void(int32_t number)
    {
        char buf[32]; // Buffer for 32-bit int string
        int len = snprintf(buf, sizeof(buf), "%d", number);
        if (len > 0) {
            write(1, buf, len);
        }
    }

    void nebula_core_io_Console_print__long__void(int64_t number)
    {
        char buf[32]; // Buffer for 64-bit int string
        // Use %lld for long long, which int64_t typically is
        int len = snprintf(buf, sizeof(buf), "%lld", static_cast<long long>(number));
        if (len > 0) {
            write(1, buf, len);
        }
    }

    // Floating point types use C library for controlled output
    void nebula_core_io_Console_print__float__void(float number)
    {
        char buf[128]; // Buffer for float string formatting
        int len = snprintf(buf, sizeof(buf), "%g", number);
        if (len > 0) {
            write(1, buf, len);
        }
    }

    void nebula_core_io_Console_print__double__void(double number)
    {
        char buf[256]; // Buffer for double string formatting
        int len = snprintf(buf, sizeof(buf), "%g", number);
        if (len > 0) {
            write(1, buf, len);
        }
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
    // These functions require no changes, as they delegate to the
    // print_* methods (which are now fixed) and println__void (which was correct).

    void nebula_core_io_Console_println__Object___void(void *anything)
    {
        nebula_core_io_Console_print__Object___void(anything);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__bool___void(bool boolean)
    {
        nebula_core_io_Console_print__bool__void(boolean);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__char___void(char character)
    {
        nebula_core_io_Console_print__char__void(character);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__string___void(const nebula_String_t *anyString)
    {
        nebula_core_io_Console_print__string__void(anyString);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__byte___void(int8_t number)
    {
        nebula_core_io_Console_print__byte__void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__short___void(int16_t number)
    {
        nebula_core_io_Console_print__short__void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__int___void(int32_t number)
    {
        nebula_core_io_Console_print__int__void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__long___void(int64_t number)
    {
        nebula_core_io_Console_print__long__void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__float___void(float number)
    {
        nebula_core_io_Console_print__float__void(number);
        nebula_core_io_Console_println___void();
    }

    void nebula_core_io_Console_println__double___void(double number)
    {
        nebula_core_io_Console_print__double__void(number);
        nebula_core_io_Console_println___void();
    }
    /*

    // --- Input Methods ---
    // (This section is unchanged, but std::cin from <iostream> would be needed)
    // Implementation relies on C++ iostream and the create_heap_string helper
    // (which must be linked from Primitives.cpp or defined here).

    // NOTE: For now, we assume create_heap_string is available via linking.
    extern string *create_heap_string(const char *c_str);

    string *nebula_core_io_Console_readLine__string()
    {
        // This function would require <iostream> and <string> to be re-included
        // if it were to be uncommented and compiled.
        std::string line;
        // std::getline is thread-safe and robust for line reading.
        if (std::getline(std::cin, line))
        {
            // Must return a heap-allocated Nebula String object (String*)
            return create_heap_string(line.c_str());
        }
        // Return an empty string on EOF/failure
        return create_heap_string("");
    }
    */

} // extern "C"