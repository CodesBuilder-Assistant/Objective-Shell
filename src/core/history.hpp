#ifndef HISTORY_HPP
#define HISTORY_HPP
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
typedef struct _command_history_unit_struct_
{
    wchar_t *command;
    _command_history_unit_struct_ *last;
    _command_history_unit_struct_ *next;
}command_history_unit;
command_history_unit *command_history;
void InitializeCommandHistoryList(void)
{
    command_history=new command_history_unit[1];
    command_history[0].command={NULL};
}
void MoveHistoryPointerToTop(void)
{
    for()
}
#endif