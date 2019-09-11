#ifndef CONTROLS_HPP
#define CONTROLS_HPP
#include <Windows.h>

IMGBUTTON current_this_ptr;

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

class IMGBUTTON
{
    private:
        HMENU return_value;
    public:
        IMGBUTTON(void)
        {
        }
};
#endif