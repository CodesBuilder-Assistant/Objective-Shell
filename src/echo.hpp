#ifndef ECHO_HPP
#define ECHO_HPP
#include <wchar.h>
#ifdef __linux
#elif defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#endif
void echo(wchar_t *output_string,bool raw)
{
    for(int i=0;i<wcslen(output_string);i++)
        if(output_string[i]==L'\0')
            return;
        else if(output_string[i]==L'\u00a7')
        {
            i+=1;
            switch(output_string[i])
            {
                case L'0':

            }
        }
}
#endif