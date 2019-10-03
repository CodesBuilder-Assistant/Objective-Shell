#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <wchar.h>
enum commands
{
    ADD=0,
    SUBTRACT,
    MULTIPLE,
    DIVISION,
    MODULE,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    AND,
    OR,
    XOR,
    IF,
    ELIF,
    ELSE,
    VAR,
    MACRO,
    UNDEFINE,
    REDEFINE,
    VARACCESS,
    CLASSACCESS,
};

void EncryptCommand(const wchar_t *command,wchar_t *buffer)
{
    wchar_t *encrypted_command=new wchar_t[wcslen(command)+1];
    for(int i=0;i<wcslen(command)-1;i++)
        encrypted_command[i]=~(command[i]+3);
    wcscpy(buffer,encrypted_command);
    delete[] encrypted_command;
}
const wchar_t *DecryptCommand(const wchar_t *command,wchar_t *buffer)
{
    wchar_t *decrypted_command=new wchar_t[wcslen(command)+1];
    for(int i=0;i<wcslen(command)-1;i++)
        decrypted_command[i]=~command[i],decrypted_command-=3;
    wcscpy(buffer,decrypted_command);
    delete[] decrypted_command;
}

#endif