/*
 * srcstat.cpp:Source statistic
 * Copyright(C)2019 CodesBuilder<2602783536@qq.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#elif defined(__linux__)
#include <boost/filesystem.hpp>
#endif
#include <filelist.hpp>
#include "languages.h"
using namespace std;

int main(int argc,char *argv[])
{
    puts("Statisticing...");
    file_list finddata(L"*.c");
    finddata.attach(L"*.h");

    printf("C:");
}