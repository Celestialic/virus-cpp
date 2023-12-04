#include <Windows.h>

int main() {

    HWND hwnd = GetConsoleWindow();

    ShowWindow(hwnd, SW_HIDE);

    Sleep(10000)

    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

    Sleep(5000);

    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);

    return 0;
}
