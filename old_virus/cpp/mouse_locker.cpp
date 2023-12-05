#include <Windows.h>

int main() {

    HWND hwnd = GetConsoleWindow();

    ShowWindow(hwnd, SW_HIDE);

    Sleep(10000);

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    while (true) {
        SetCursorPos(centerX, centerY);

    }

    return 0;
}
