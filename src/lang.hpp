#ifndef LANG_HPP
#define LANG_HPP
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <string>
#ifdef __linux
#elif defined(_WIN32)||defined(_WIN64)
#include <conio.h>
#include <windows.h>
#endif
#define LANGUAGE_ID_MAX 5
char *language_select_menu_titles[]={"en-us","zh-hans","zh-hant"};
enum language_id
{
    EN_US=0,
    ZH_HANS,
    ZH_HANT,
    AUTO_DETECT
};
unsigned short current_selected_lang_id=EN_US;
__fastcall void ReadLanguageFile(unsigned short lang_id)
{
    switch(lang_id)
    {

    }
}
void ShowLanguageSetting(void)
{
    puts("Language Setting\n");
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    int gotkey,selected=0;
    while(true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
        printf(".-------------");
        if(selected!=-1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
        puts("|x|");
        if(selected<4)
            for(int i=0;i<4;i++)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("|");
				if(i==selected)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_BLUE);
				printf("%-12s",language_select_menu_titles[i]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("|");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
				puts(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
		printf("'---------------'");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
		puts(" ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		printf(" ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
		puts("                 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        gotkey=getch();
        switch(gotkey)
        {
            case 72:
                if(selected>=0)
                    selected--;
                break;
            case 80:
                if(selected<LANGUAGE_ID_MAX-1)
                    selected++;
                break;
            case VK_RETURN:
                if(selected==-1)
                {
                    system("cls");
                    return;
                }
                break;
        }
        system("cls");
    }
    #endif
}
#endif