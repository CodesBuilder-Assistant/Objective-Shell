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
#define LANGUAGE_ID_MAX 3
char *language_select_menu_shows[]={"en-us","zh-hans","zh-hant"};
enum language_id
{
    EN_US=0,
    ZH_HANS,
    ZH_HANT
};
unsigned short current_selected_lang_id=EN_US;
void ReadLanguageFile(unsigned short lang_id)
{
    switch(lang_id)
    {
        
    }
}
void ShowLanguageSetting(void)
{
    puts("Language Setting\n");
    puts("=====================");
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    int user_kbhit;
    unsigned short selected_lang_id=current_selected_lang_id;
    while(true)
    {
        for(int i=0;i<LANGUAGE_ID_MAX;i++)
            if(i+4==selected_lang_id||i+3==selected_lang_id||i+2==selected_lang_id||i+1==selected_lang_id||\
            i-1==selected_lang_id||i-2==selected_lang_id||i-3==selected_lang_id||i-4==selected_lang_id)
                printf("%s",language_select_menu_shows[i]);
            else if(i==selected_lang_id)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
                printf("%s",language_select_menu_shows[i]);
            }
        puts("=====================");
        switch((user_kbhit=getch()))
        {
            case VK_UP:
                selected_lang_id--;
                break;
            case VK_DOWN:
                selected_lang_id++;
                break;
            case VK_RETURN:
                goto SetupLanguage;
                break;
        }
    }
    SetupLanguage:
    system("cls");
    current_selected_lang_id=selected_lang_id;
    #endif
}
#endif