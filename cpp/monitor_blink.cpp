#include <Windows.h>

int main() {

    // Получаем дескриптор окна консоли
    HWND hwnd = GetConsoleWindow();

    // Скрываем окно консоли
    ShowWindow(hwnd, SW_HIDE);

    // Выключение монитора
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

    // Ждем 5 секунду
    Sleep(5000);

    // Включение монитора
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);

    return 0;
}
