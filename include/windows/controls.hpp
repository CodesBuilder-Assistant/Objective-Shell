#ifndef CONTROLS_HPP
#define CONTROLS_HPP
#include <Windows.h>
#include <list>
using std::list;

extern LRESULT CALLBACK ImageButtonProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

bool imgbutton_class_registered=false;

WNDCLASSW __imgbutton__;

void RegisterImageButtonClass(void)
{
    if(!imgbutton_class_registered)
    {
        __imgbutton__={};
        imgbutton_class_registered=true;
    }
}

class IMGBUTTON
{
    private:
        HMENU return_value;
        HWND button_handle;
        HWND parent_handle;
        friend LRESULT CALLBACK ImageButtonProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
        POINT button_position;
    public:
        IMGBUTTON(void)
        {
            RegisterImageButtonClass();
        }
        IMGBUTTON(UINT x,UINT y,WORD width,WORD height,HMENU return_menu_value,HWND parent_window)
        {
            RegisterImageButtonClass();
        }
};

LRESULT CALLBACK ImageButtonProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CREATE:
            
        case WM_LBUTTONDBLCLK:
            SendMessageW(GetParent(hwnd),WM_COMMAND,NULL,);
            break;
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

#endif