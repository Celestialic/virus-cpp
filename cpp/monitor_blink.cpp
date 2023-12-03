#include <Windows.h>

int main() {
    // Выключение монитора
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

    // Ждем 1 секунду
    Sleep(3000);

    // Включение монитора
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);

    return 0;
}
