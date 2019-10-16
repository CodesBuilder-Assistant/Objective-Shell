#ifndef VERSION_HPP
#define VERSION_HPP
#include <stdio.h>
#include <effects.hpp>
void ShowVersionInformation(void) noexcept
{
    SetConsoleTextColor(LIGHTBLUE);
    puts("\nObjective Shell");
    SetConsoleTextColor(LIGHTGREEN);
    puts("Codename 'Quartz'\n");
    SetConsoleTextColor(WHITE);
    puts("1.0.0.0005(Secret Test 2) (Build 5)\n");
    puts("For testing purposes only\n");
    SetConsoleTextColor(RED);
    puts("Confidential Version");
}
#endif