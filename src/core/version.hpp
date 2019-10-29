#ifndef VERSION_HPP
#define VERSION_HPP
#include <stdio.h>
#include <effects.hpp>
unsigned int build=32;
void ShowVersionInformation(void) noexcept
{
    SetConsoleTextColor(LIGHTBLUE);
    puts("\nObjective Shell");
    SetConsoleTextColor(LIGHTGREEN);
    puts("Codename 'Quartz'\n");
    SetConsoleTextColor(LIGHTRED);
    puts("==========Testing Version==========\n");
    SetConsoleTextColor(WHITE);
    puts("Version:");
    SetConsoleTextColor(GREEN);
    printf("1.0.0.%d\n\n",build);
    SetConsoleTextColor(WHITE);
    puts("Build Date&Time:");
    SetConsoleTextColor(YELLOW);
    printf("%s\n %s\n\n",__DATE__,__TIME__);
    SetConsoleTextColor(LIGHTBLUE);
    puts("For testing purposes only\n");
    SetConsoleTextColor(WHITE);
}
#endif