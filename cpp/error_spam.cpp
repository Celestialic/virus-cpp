#include <Windows.h>

int main()
{

    HWND hwnd = GetConsoleWindow();

    ShowWindow(hwnd, SW_HIDE);

    Sleep(10000);

    for (int i = 0; i < 25; i++)
    {
        MessageBox(NULL, "FATTAL ERROR", "SYS32 CORRUPTED", MB_OK | MB_ICONERROR);
    }
    return 0;
}
