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
    }
    else if(id%11==0)
    {
    }
    else if(id%13==0)
    {
    }
    else if(id%19==0)
    {
    }
    else if(id%23==0)
}
#endif