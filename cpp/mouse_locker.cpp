#include <Windows.h>

int main() {
    // Get the screen dimensions
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Calculate the center coordinates
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    // Infinite loop to keep moving the mouse to the center
    while (true) {
        // Set the mouse position
        SetCursorPos(centerX, centerY);

    }

    return 0;
}
