#ifndef STARTUP_HPP
#define STARTUP_HPP
#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <unistd.h>
#endif
void PaintStartupAnimation(void)
{

}
#endif