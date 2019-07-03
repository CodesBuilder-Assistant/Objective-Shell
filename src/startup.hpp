#ifndef STARTUP_HPP
#define STARTUP_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#include <unistd.h>
#endif
void PaintStartupAnimation(void)
{
    /* TODO:Add the paint startip animation codes.
     * I don't have any idea. */

}
#endif