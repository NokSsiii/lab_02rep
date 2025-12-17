#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

void main()
{
    puts("Lab: Variant 25. Part 2 - Compiler Options Check");
    puts("-------------------------------------------------");

#if defined(_DEBUG)
    puts("[INFO]: Configuration is set to DEBUG.");
    puts("        (Debugging symbols are enabled, optimization is low).");
#elif defined(NDEBUG)
    puts("[INFO]: Configuration is set to RELEASE.");
    puts("        (Code is optimized, debugging info is minimal).");
#else
    puts("[WARN]: Unknown configuration (neither _DEBUG nor NDEBUG defined).");
#endif

#if defined(__cplusplus)
    puts("[INFO]: Compiled as C++ code.");
#else
    puts("[INFO]: Compiled as standard C code.");
#endif

#if defined(_WIN32) || defined(_WIN64)
    puts("[INFO]: Target OS: Windows.");
#elif defined(__linux__)
    puts("[INFO]: Target OS: Linux.");
#elif defined(__APPLE__)
    puts("[INFO]: Target OS: MacOS.");
#else
    puts("[INFO]: Target OS: Unknown.");
#endif

    puts("\n--- Checking constraints ---");

#if defined(_DEBUG)
    puts("[SUCCESS]: Compiler options are correct (Debug mode is active).");
#else
    puts("[ERROR]: Compiler options are INCORRECT!");
    puts("         Please switch to Debug configuration to run this lab properly.");
#endif

#if defined(DEMO_ERROR_MODE)
    puts("[TEST]: Manual error mode is ON.");
#endif

    puts("\nPress any key to exit...");
    _getch();
}