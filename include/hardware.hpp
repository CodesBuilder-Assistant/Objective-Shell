#ifndef HARDWARE_HPP
#define HARDWARE_HPP
#include <thread>
#ifdef _WIN32
#include <Windows.h>
#endif
using std::thread;
unsigned char GetCpuCoreCount(void)
{
    return thread::hardware_concurrency();
}
/*
unsigned long long GetMemorySize(void)
{
    MEMORYSTATUS memstat;
    memstat.dwLength=sizeof(memstat);
    GlobalMemoryStatus(&memstat);
    memstat.dwTotalPhys;
    return memstat.dwTotalPhys;
}*/
#endif