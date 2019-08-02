#ifndef UISCRIPT_H
#define UISCRIPT_H
#include <stdio.h>
#include <wchar.h>
#include <string>
#include <vector>
#include <list>
using namespace std;
extern short ExecCommand(wstring one_line_of_command);

namespace setting_interface_script
{
    const wchar_t *cmd_menu=L"menu";
    const wchar_t *cmd_submenu=L"submenu";
    const wchar_t *cmd_button=L"button";
    const wchar_t *cmd_out=L"out";
    const wchar_t *cmd_alert=L"alert";
    const wchar_t *cmd_ret=L"ret";
    const wchar_t *cmd_call=L"call";
    const wchar_t *cmd_goto=L"goto";
    class menu
    {
        private:
            menu *parent_menu;
            list<menu*>child_menus;
            list<menu*>child_buttons;
        public:
            menu(void)
            {
                this->parent_menu=NULL;
            }
            menu(menu *parent_menu)
            {
                this->parent_menu=parent_menu;
            }
    };

    void ExecCommand(const wchar_t *command)
    {
        wstring crtpart;
        vector<wstring>parts;
        unsigned short need_end_cnt;
        for(register int i=0;i<wcslen(command);i++)
            if(command[i]==L' '||i==wcslen(command))
            {
                parts.push_back(crtpart);
                crtpart.clear();
            }
        for(register int i=0;i<parts.size();i++)
            if(parts[i].c_str()==cmd_menu)
            {

            }
            else
            {
                crtpart.clear();
                for(register int i=0;i<parts.size();i++)
                {
                    crtpart+=parts[i];
                    crtpart+=L" ";
                }
                ::ExecCommand(crtpart.c_str());
            }
    }
}
#endif