#include <windows.h>

int main() {
    const int numProcesses = 25;

    HWND hwnd = GetConsoleWindow();

    ShowWindow(hwnd, SW_HIDE);

    Sleep(10000);

    for (int i = 0; i < numProcesses; ++i) {
        STARTUPINFO siCalc = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION piCalc;
        CreateProcess(NULL, "calc.exe", NULL, NULL, FALSE, 0, NULL, NULL, &siCalc, &piCalc);
        CloseHandle(piCalc.hProcess);
        CloseHandle(piCalc.hThread);
    }

    for (int i = 0; i < numProcesses; ++i) {
        STARTUPINFO siNotepad = { sizeof(STARTUPINFO) };
        PROCESS_INFORMATION piNotepad;
        CreateProcess(NULL, "notepad.exe", NULL, NULL, FALSE, 0, NULL, NULL, &siNotepad, &piNotepad);
        CloseHandle(piNotepad.hProcess);
        CloseHandle(piNotepad.hThread);
    }

    return 0;
}
