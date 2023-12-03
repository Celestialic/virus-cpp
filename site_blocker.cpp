#include <iostream>
#include <fstream>

int main() {
    // Получаем путь к системному файлу hosts
    const char* hostsPath = "C:\\Windows\\System32\\drivers\\etc\\hosts";

    // Добавляем запись для блокировки доступа к YouTube.com
    std::ofstream hostsFile(hostsPath, std::ios::app);
    if (hostsFile.is_open()) {
        hostsFile << "\n127.0.0.1    youtube.com";
        hostsFile << "\n127.0.0.1    www.youtube.com";
        hostsFile << "\n127.0.0.1    vk.com";
        hostsFile << "\n127.0.0.1    www.vk.com";
        hostsFile.close();
        std::cout << "YouTube.com is blocked." << std::endl;
    } else {
        std::cerr << "Unable to open hosts file." << std::endl;
        return 1;
    }

    return 0;
}
