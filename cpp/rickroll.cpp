#include <windows.h>

int main() {
    const int numProcesses = 25;

    // Получаем дескриптор окна консоли
    HWND hwnd = GetConsoleWindow();

    // Скрываем окно консоли
    ShowWindow(hwnd, SW_HIDE);

    // Запуск 25 калькуляторов
    for (int i = 0; i < numProcesses; ++i) {
        STARTUPINFO siCalc = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION piCalc;
        CreateProcess(NULL, "calc.exe", NULL, NULL, FALSE, 0, NULL, NULL, &siCalc, &piCalc);
        CloseHandle(piCalc.hProcess);
        CloseHandle(piCalc.hThread);
    }

    // Запуск 25 блокнотов
    for (int i = 0; i < numProcesses; ++i) {
        STARTUPINFO siNotepad = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION piNotepad;
        CreateProcess(NULL, "notepad.exe", NULL, NULL, FALSE, 0, NULL, NULL, &siNotepad, &piNotepad);
        CloseHandle(piNotepad.hProcess);
        CloseHandle(piNotepad.hThread);
    }

    return 0;
}
