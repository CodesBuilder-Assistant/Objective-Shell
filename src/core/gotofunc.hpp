/*
*   /\
*  /  \
* |\   \
* | \   \
*  \ \   \
*   \ \   \
*   / /   /
*  / /   /
* / /   /
* |/   /   ______
*  \  /   /______\
*   \/   |________|
*
*/
#ifndef GOTOFUNC_HPP
#define GOTOFUNC_HPP
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <unistd.h>
#endif
/* You found the Easter Eggs codes! */
void ShowRandomContents(void)
{
    size_t id;
    srand(time(NULL));
    id=time(NULL);
    if(id%17==0)
    {
        puts("You found an Easter Egg!");
        puts("Try more values to find more Easter Eggs!");
    }
    else if(id%11==0)
    {
        #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);
        #elif defined(__linux__)
        printf("\033[37;47m");
        #endif
        puts("There are NO Easter Eggs in this program.");
        #ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        #elif defined(__linux__)
        printf("\033[0m");
        #endif
    }
    else if(id%13==0)
    {
        puts("There is a credits Easter Egg in this progran.");
        puts("Want to find it? Please try more values!");
    }
    else if(id%19==0)
    {
    }
    else if(id%23==0)
    {

    }
}
#endif