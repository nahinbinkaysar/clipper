// Clipper.cpp : Defines the entry point for the application.
//
#pragma comment(lib, "ComCtl32.lib")
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


#include "framework.h"
#include "Clipper.h"
#include <dwmapi.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

INT_PTR CALLBACK    Main(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, Main);

}

INT_PTR CALLBACK Main(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL dark = TRUE;
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        ::DwmSetWindowAttribute(hDlg, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark, sizeof(dark));
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDC_COPY) {
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event(0x43, 0, 0, 0); // 'C' key
            keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDC_PASTE) {
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event(0x56, 0, 0, 0); // 'V' key
            keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDC_DUPLICATE) {
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event(0x43, 0, 0, 0); // 'C' key
            keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            Sleep(400);

            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event(0x56, 0, 0, 0); // 'V' key
            keybd_event(0x56, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            return (INT_PTR)TRUE;
        }

        break;
    }
    return (INT_PTR)FALSE;
}
