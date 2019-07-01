#ifndef GOTOFUNC_HPP
#define GOTOFUNC_HPP
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#include <unistd.h>
#endif
void ShowRandomContents(void)
{
    srand(RAND_MAX);
    unsigned short random_id=rand();
    if(random_id%2==0)
    {
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        #elif defined(__linux)
        printf("\033[2J\033[0m");
        #endif
        printf("C:>");
        #if defined(_WIN32)||defined(_WIN64)
        Sleep(2250);
        #elif defined(__linux)
        sleep(3);
        #endif
        printf("ob");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>ob");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objs");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objshe");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objshell");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        puts("");
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        return;
    }
    else if(random_id%3==0)
    {
        string entered_passwd="NULL";
        while(entered_passwd!="AD21J-OD243-P2HGJ-GH23L-T74YS"&&entered_passwd!="FGS52-LBG24-UED34-M54ND-AURH5")
        {
            if(entered_passwd.empty())
                puts("Password error.");
            entered_passwd="";
            puts("Tip:Input empty password to exit");
            printf("Enter password(Explame:XXXXX-XXXXX-XXXXX-XXXXX-XXXXX):");
            cin>>entered_passwd;
            if(entered_passwd.empty())
                return;
            puts("");
        }
        puts("Loading...");
        #if defined(_WIN32)||defined(_WIN64)
        for(register int i=0;i<64;i++)
        {
            printf("\b[                ]");
		    Sleep(100);
		    printf("\r[");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf(" ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("               ]");
    		Sleep(100);
		    printf("\r[");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("  ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("              ]");
    		Sleep(100);
		    printf("\r[");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("             ]");
    		Sleep(100);
		    printf("\r[ ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("            ]");
    		Sleep(100);
		    printf("\r[  ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("           ]");
    		Sleep(100);
		    printf("\r[   ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("          ]");
    		Sleep(100);
		    printf("\r[    ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("         ]");
    		Sleep(100);
		    printf("\r[     ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("        ]");
    		Sleep(100);
		    printf("\r[      ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("       ]");
    		Sleep(100);
		    printf("\r[       ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("      ]");
    		Sleep(100);
		    printf("\r[        ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("     ]");
    		Sleep(100);
		    printf("\r[         ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
		    printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("    ]");
    		Sleep(100);
		    printf("\r[          ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("   ]");
    		Sleep(100);
		    printf("\r[           ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("  ]");
    		Sleep(100);
		    printf("\r[            ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf(" ]");
    		Sleep(100);
		    printf("\r[             ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("   ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("]");
    		Sleep(100);
		    printf("\r[              ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf("  ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("]");
    		Sleep(100);
		    printf("\r[               ");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    		printf(" ");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	    	printf("]");
	    	Sleep(100);
    		printf("\r");
        }
        #elif defined(__linux)
        for(register int i=0;i<64;i++)
        {
            printf("\b[                ]");
		    usleep(100000);
		    printf("\r[");
	    	printf("\033[92m");
    		printf(" ");
		    printf("\033[0m");
	    	printf("               ]");
    		usleep(100000);
		    printf("\r[");
	    	printf("\033[92m");
    		printf("  ");
		    printf("\033[0m");
	    	printf("              ]");
    		usleep(100000);
		    printf("\r[");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("             ]");
    		usleep(100000);
		    printf("\r[ ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("            ]");
    		usleep(100000);
		    printf("\r[  ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("           ]");
    		usleep(100000);
		    printf("\r[   ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("          ]");
    		usleep(100000);
		    printf("\r[    ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("         ]");
    		usleep(100000);
		    printf("\r[     ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("        ]");
    		sleep(100);
		    printf("\r[      ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("       ]");
    		usleep(100000);
		    printf("\r[       ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("      ]");
    		usleep(100000);
		    printf("\r[        ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("     ]");
    		usleep(100000);
		    printf("\r[         ");
		    printf("\033[92m");
		    printf("   ");
		    printf("\033[0m");
	    	printf("    ]");
    		usleep(100000);
		    printf("\r[          ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("   ]");
    		usleep(100000);
		    printf("\r[           ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("  ]");
    		usleep(100000);
		    printf("\r[            ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf(" ]");
    		usleep(100000);
		    printf("\r[             ");
	    	printf("\033[92m");
    		printf("   ");
		    printf("\033[0m");
	    	printf("]");
    		usleep(100000);
		    printf("\r[              ");
	    	printf("\033[92m");
    		printf("  ");
		    printf("\033[0m");
	    	printf("]");
    		usleep(100000);
		    printf("\r[               ");
	    	printf("\033[92m");
    		printf(" ");
		    printf("\033[0m");
	    	printf("]");
	    	usleep(100000);
    		printf("\r");
        }
        #endif
        printf("\b[                ]");
        #if defined(_WIN32)||defined(_WIN64)
        CONSOLE_CURSOR_INFO curinfo;
        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curinfo);
        curinfo.bVisible=false;
	    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curinfo);
        #elif defined(__linux)
        printf("\033[?25l");
        #endif
        puts("\n\aError loading file.");
    }
}
void ASCIITable(void)
{
    for(char i=0;i<127;i++)
    {
        puts(" Character  Value");
        printf("  %c          %d\n",i,(int)i);
    }
}
void BugReport(void)
{
    #ifdef __linux
    printf("\033[2J");
    #elif defined(_WIN32)||defined(_WIN64)
    system("cls");
    #endif
    printf("To report bugs of Objective Shell,please visit:\n");
    #ifdef __linux
    puts("\033[4;32mhttps://github.com/CodesBuilder/Objective-Shell/issues\033[0m");
    printf("\033[?25l");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|COMMON_LVB_UNDERSCORE);
    puts("https://github.com/CodesBuilder/Objective-Shell/issues");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    CONSOLE_CURSOR_INFO curinfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curinfo);
    curinfo.bVisible=false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curinfo);
	#endif
    puts("Press enter to back...");
    getchar();
    rewind(stdin);
    #ifdef __linux
    printf("\033[?25h");
    #elif defined(_WIN32)||defined(_WIN64)
    curinfo.bVisible=true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curinfo);
    #endif
}
#endif