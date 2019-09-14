#ifndef CUSTOM_CONTROLS_HPP
#define CUSTOM_CONTROLS_HPP
#include <Windows.h>
WNDCLASSW normal_button;

LRESULT CALLBACK NormalButtonProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {

        case WM_CREATE:
            SendMessageW(hwnd,WM_SHOWWINDOW,NULL,NULL);
            break;
    }
}

void RegisterControls(void)
{

}
#endif