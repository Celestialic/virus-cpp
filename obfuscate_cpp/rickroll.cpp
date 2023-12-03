#include <windows.h>

#define OBF_NUM_PROCESSES 25

#define OBF_SHELL_WINDOW GetConsoleWindow()
#define OBF_HIDE_CONSOLE ShowWindow(OBF_SHELL_WINDOW, SW_HIDE)

#define OBF_CREATE_PROCESS(app) \
    for (int i = 0; i < OBF_NUM_PROCESSES; ++i) { \
        STARTUPINFO si = { sizeof(STARTUPINFO) }; \
        PROCESS_INFORMATION pi; \
        CreateProcess(NULL, app, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

int main() {
    OBF_HIDE_CONSOLE;
    OBF_CREATE_PROCESS("calc.exe");
    OBF_CREATE_PROCESS("notepad.exe");
    return 0;
}
