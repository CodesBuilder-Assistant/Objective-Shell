#ifndef SETTING_INTERFACE_SCRIPT
#define SETTING_INTERFACE_SCRIPT
#include <stdio.h>
#include <wchar.h>
#include <string>
#include <vector>
using namespace std;
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
    void ExecCommand(wchar_t *command)
    {
        wstring crtpart;
        vector<wstring>parts;
        unsigned short need_end_cnt;
        for(int i=0;i<wcslen(command);i++)
            if(command[i]==L' '||i==wcslen(command))
            {
                parts.push_back(crtpart);
                crtpart.clear();
            }
        for(int i=0;i<parts.size();i++)
            ;
    }
}
#endif