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
    puts("==========Confidential Version==========\n");
    SetConsoleTextColor(WHITE);
    puts("1.0.0.0009(Secret Test 3) (Build 9)\n");
    puts("For testing purposes only\n");
    SetConsoleTextColor(RED);
    SetConsoleTextColor(WHITE);
}
#endif