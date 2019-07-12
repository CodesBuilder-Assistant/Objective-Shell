#include <stdio.h>
#ifdef __linux__
#include <sys/io.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <io.h>
#include <Windows.h>
#endif
int main(int argc,char *argv[])
{
    if(argv>1)
    {
        for(register int i=0;i<argc;i++)
        {
            if(_access(argv[i],0)==-1)
            {
                #ifdef __linux__
                printf("\033[0m[\033[31mError\033[0m]Directory '%d' does not exist",argv[i]);
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("]");
                printf("Directory '%d' does not exist",argv[i]);
                continue;
                #endif
            }

        }
    }
    return 0;
}