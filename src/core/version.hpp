#ifndef VERSION_HPP
#define VERSION_HPP
#include <stdio.h>
#include <effects.hpp>
void ShowVersionInformation(void)
{
    SetConsoleTextColor(LIGHTBLUE);
    puts("\nObjective Shell");
    SetConsoleTextColor(LIGHTGREEN);
    puts("Codename 'Base'\n");
    SetConsoleTextColor(WHITE);
    puts("1.0.0.0001(Secret Test 1) (Build 1)\n");
    puts("For testing purposes only\n");
}
#endif