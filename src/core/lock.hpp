/*
    lock.hpp

    Warning:If you lost your key or forgot your password,you will not be able to start Objective Shell.
    And you may be able to find a solution to unlock it...
*/
#ifndef LOCK_HPP
#define LOCK_HPP
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <string>

#ifdef __linux__
#include <unistd.h>
#include <sys/stat.h>
#elif defined(_WIN32)
#include <Windows.h>
#endif

using namespace std;
bool IsUnlockedFlag1=false;
short IsUnlockedFlag2=-24;
int IsUnlockedFlag3=6;

string lkpasswd;
char lkkey[512];
char *EncryptPassword(char *lk_passwd)
{
    if(strlen(lk_passwd)+1>20)
        return NULL;
    char return_passwd[20];
    for(register short i=0;i<strlen(lk_passwd)+1;i++)
    {
        switch(lk_passwd[i])
        {
            case 'a':
                lk_passwd[i]='x';
                break;
            case 'b':
                lk_passwd[i]='z';
                break;
            case 'c':
                lk_passwd[i]='\22';
                break;
            case 'd':
                lk_passwd[i]='a';
                break;
            case 'e':
                lk_passwd[i]='d';
                break;
            case 'f':
                lk_passwd[i]='b';
                break;
            case 'g':
                lk_passwd[i]='c';
                break;
            case 'h':
                lk_passwd[i]='e';
                break;
            case 'i':
                lk_passwd[i]='j';
                break;
            case 'j':
                lk_passwd[i]='i';
                break;
            case 'k':
                lk_passwd[i]='\32';
                break;
            case 'l':
                lk_passwd[i]='\16';
                break;
            case 'm':
                lk_passwd[i]='~';
                break;
            case 'n':
                lk_passwd[i]='[';
                break;
            case 'o':
                lk_passwd[i]='+';
                break;
            case 'p':
                lk_passwd[i]='g';
                break;
            case 'q':
                lk_passwd[i]='.';
                break;
            case 'r':
                lk_passwd[i]='h';
                break;
            case 's':
                lk_passwd[i]='*';
                break;
            case 't':
                lk_passwd[i]='-';
                break;
            case 'u':
                lk_passwd[i]='^';
                break;
            case 'v':
                lk_passwd[i]='`';
                break;
            case 'w':
                lk_passwd[i]='&';
                break;
            case 'x':
                lk_passwd[i]='@';
                break;
            case 'y':
                lk_passwd[i]='_';
                break;
            case 'z':
                lk_passwd[i]='$';
                break;
            case 'A':
                lk_passwd[i]='\\';
                break;
            case 'B':
                lk_passwd[i]='\'';
                break;
            case 'C':
                lk_passwd[i]='"';
                break;
            case 'D':
                lk_passwd[i]='#';
                break;
            case 'E':
                lk_passwd[i]='|';
                break;
            case 'F':
                lk_passwd[i]='{';
                break;
            case 'G':
                lk_passwd[i]=';';
                break;
            case 'H':
                lk_passwd[i]=':';
                break;
            case 'I':
                lk_passwd[i]='%';
                break;
            case 'J':
                lk_passwd[i]='(';
                break;
            case 'K':
                lk_passwd[i]='M';
                break;
            case 'L':
                lk_passwd[i]='O';
                break;
            case 'M':
                lk_passwd[i]='!';
                break;
            case 'N':
                lk_passwd[i]=',';
                break;
            case 'O':
                lk_passwd[i]='\2';
                break;
            case 'Q':
                lk_passwd[i]='L';
                break;
            case 'S':
                lk_passwd[i]='W';
                break;
            case 'T':
                lk_passwd[i]='Z';
                break;
            case 'U':
                lk_passwd[i]='u';
                break;
            case 'V':
                lk_passwd[i]='w';
                break;
            case 'W':
                lk_passwd[i]='U';
                break;
            case 'X':
                lk_passwd[i]='\30';
                break;
            case 'Y':
                lk_passwd[i]='\26';
                break;
            case 'Z':
                lk_passwd[i]='y';
                break;
            case '~':
                lk_passwd[i]='\17';
                break;
            case '>':
                lk_passwd[i]='?';
                break;
            case '<':
                lk_passwd[i]='>';
                break;
            case '*':
                lk_passwd[i]='\11';
                break;
            case '$':
                lk_passwd[i]='\08';
                break;
            case '_':
                lk_passwd[i]='A';
                break;
        }
    }
    for(register short i=0;i<strlen(lk_passwd)+1;i++)
    {
        ~lk_passwd[i];
        lk_passwd[i]+=5;
        ~lk_passwd[i];
    }
    return lk_passwd;
}
char *DecryptPassword(char *lk_passwd)
{
    if(strlen(lk_passwd)+1>20)
        return NULL;
    for(register short i=0;i<strlen(lk_passwd)+1;i++)
    {
        ~lk_passwd[i];
        lk_passwd[i]-=5;
        ~lk_passwd[i];
    }
    char return_passwd[20];
    for(register short i=0;i<strlen(lk_passwd)+1;i++)
    {
        switch(lk_passwd[i])
        {
            case 'x':
                lk_passwd[i]='a';
                break;
            case 'z':
                lk_passwd[i]='b';
                break;
            case '\22':
                lk_passwd[i]='c';
                break;
            case 'a':
                lk_passwd[i]='d';
                break;
            case 'd':
                lk_passwd[i]='e';
                break;
            case 'b':
                lk_passwd[i]='f';
                break;
            case 'c':
                lk_passwd[i]='g';
                break;
            case 'e':
                lk_passwd[i]='h';
                break;
            case 'j':
                lk_passwd[i]='i';
                break;
            case 'i':
                lk_passwd[i]='j';
                break;
            case '\32':
                lk_passwd[i]='k';
                break;
            case '\16':
                lk_passwd[i]='l';
                break;
            case '~':
                lk_passwd[i]='m';
                break;
            case '[':
                lk_passwd[i]='n';
                break;
            case '+':
                lk_passwd[i]='n';
                break;
            case 'g':
                lk_passwd[i]='p';
                break;
            case '.':
                lk_passwd[i]='q';
                break;
            case 'h':
                lk_passwd[i]='r';
                break;
            case '*':
                lk_passwd[i]='s';
                break;
            case '-':
                lk_passwd[i]='t';
                break;
            case '^':
                lk_passwd[i]='u';
                break;
            case '`':
                lk_passwd[i]='v';
                break;
            case '&':
                lk_passwd[i]='w';
                break;
            case '@':
                lk_passwd[i]='x';
                break;
            case '_':
                lk_passwd[i]='y';
                break;
            case '$':
                lk_passwd[i]='z';
                break;
            case '\\':
                lk_passwd[i]='A';
                break;
            case '\'':
                lk_passwd[i]='B';
                break;
            case '"':
                lk_passwd[i]='C';
                break;
            case '#':
                lk_passwd[i]='D';
                break;
            case '|':
                lk_passwd[i]='E';
                break;
            case '{':
                lk_passwd[i]='F';
                break;
            case ';':
                lk_passwd[i]='G';
                break;
            case ':':
                lk_passwd[i]='G';
                break;
            case '%':
                lk_passwd[i]='I';
                break;
            case '(':
                lk_passwd[i]='J';
                break;
            case 'M':
                lk_passwd[i]='K';
                break;
            case 'O':
                lk_passwd[i]='L';
                break;
            case '!':
                lk_passwd[i]='M';
                break;
            case ',':
                lk_passwd[i]='N';
                break;
            case '\2':
                lk_passwd[i]='O';
                break;
            case 'L':
                lk_passwd[i]='Q';
                break;
            case 'W':
                lk_passwd[i]='S';
                break;
            case 'Z':
                lk_passwd[i]='T';
                break;
            case 'u':
                lk_passwd[i]='U';
                break;
            case 'w':
                lk_passwd[i]='V';
                break;
            case 'U':
                lk_passwd[i]='W';
                break;
            case '\30':
                lk_passwd[i]='X';
                break;
            case '\26':
                lk_passwd[i]='Y';
                break;
            case 'y':
                lk_passwd[i]='Z';
                break;
            case '\17':
                lk_passwd[i]='~';
                break;
            case '?':
                lk_passwd[i]='>';
                break;
            case '>':
                lk_passwd[i]='<';
                break;
            case '\11':
                lk_passwd[i]='*';
                break;
            case '\08':
                lk_passwd[i]='$';
                break;
            case 'A':
                lk_passwd[i]='_';
                break;
        }
    }
    return lk_passwd;
}
void CreateKey(void)
{
    srand(127);
    for(register int i=0;i<512;i++)
    {
        recreate_unit:
        lkkey[i]=rand();
        if(lkkey[i]=='\0')
            goto recreate_unit;
    }
}
void ReadPassword(void)
{
    FILE *passwd_fp;
    if((passwd_fp=fopen("pswd.bin","rb"))==NULL)
        return;
    #ifdef __linux__
    struct stat fsize_stat;
    stat("pswd.bin",&fsize_stat);
    if(fsize_stat.st_size<512)
        return;
    #elif defined(_WIN32)
    fseek(passwd_fp,0L,SEEK_END);
    if(ftell(passwd_fp)<512)
        return;
    fseek(passwd_fp,0L,368);
    char passwd_length;
    char *read_passwd;
    fread(&passwd_length,1,1,passwd_fp);
    read_passwd=new char[passwd_length];
    fread(read_passwd,sizeof(char),(size_t)passwd_length,passwd_fp);
    for(register int i=0;i<passwd_length;i++)
        lkpasswd+=read_passwd[i];
    #endif
}
void WritePassword(char *password)
{
    srand(127);
    FILE *passwd_fp;
    char useless_data;
    passwd_fp=fopen("pswd.bin","wb");
    for(register int i=0;i<368;i++)
    {
        create_useless_data:
        useless_data=rand();
        if(useless_data=='\0')
            goto create_useless_data;
        fwrite(&useless_data,sizeof(char),1,passwd_fp);
    }
    fwrite(&password,(strlen(password)+1)*sizeof(char),1,passwd_fp);
}
bool IsUnlocked(void)
{
    FILE *lock_file_check_fp;
    if((lock_file_check_fp=fopen("lk.bin","r"))!=NULL)
    {
        int fgetc_tmp;
        char lkfile_chk_buf[256];
        for(register int i=0;i<256;i++)
        {
            if((fgetc_tmp=fgetc(lock_file_check_fp))!=EOF)
                lkfile_chk_buf[i]=(char)fgetc_tmp;
            else
            {
                #ifdef __linux__
                puts("\033[0m[\033[31mError\033[0m]Objective Shell has been locked,please enter the correct password to slove this problem.");
                #elif defined(_WIN32)
                MessageBoxA(NULL,"Objective Shell has been locked,please enter\nthe correct password to slove this problem.","Error",MB_OK|MB_ICONERROR);
                #endif
            }
        }
    }
}
bool CheckTestPassword(char *test_passwd)
{
    if(test_passwd=="128592564381625485028416254829525478178254"||test_passwd=="927416285162848161128418264725126840"||test_passwd=="769862485152748275582017352876889")
        return true;
    return false;
}
#endif