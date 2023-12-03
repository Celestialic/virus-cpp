#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>  // For _mkdir
#endif

void createTrollDirectory(const std::string& drive) {
    std::string trollDirectory = drive + ":/troll";

    // Проверяем, существует ли директория "troll"
    struct stat info;
    if (stat(trollDirectory.c_str(), &info) != 0) {
        // Создаем директорию "troll"
#ifdef _WIN32
        int result = _mkdir(trollDirectory.c_str());
#else
        int result = mkdir(trollDirectory.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

        if (result == 0) {
            std::cout << "Директория " << trollDirectory << " успешно создана\n";

            // Создаем 10 файлов размером 25 МБ внутри директории "troll"
            for (int i = 1; i <= 10; ++i) {
                std::string fileName = trollDirectory + "/file" + std::to_string(i) + ".txt";
                std::ofstream file(fileName.c_str(), std::ios::out | std::ios::binary);
                file.seekp(25 * 1024 * 1024 - 1);
                file.write("", 1);
                file.close();
                std::cout << "Файл " << fileName << " успешно создан\n";
            }
        } else {
            std::cerr << "Ошибка при создании директории " << trollDirectory << "\n";
        }
    } else {
        std::cerr << "Директория " << trollDirectory << " уже существует\n";
    }
}

int main() {
    // Получаем список доступных дисков
    for (char drive = 'A'; drive <= 'Z'; ++drive) {
        std::string drivePath = std::string(1, drive) + ":/";
        if (_access(drivePath.c_str(), 0) == 0) {
            // Диск существует, создаем директорию "troll"
            createTrollDirectory(drivePath);
        }
    }

    return 0;
}
