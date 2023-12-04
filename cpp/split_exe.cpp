#include <iostream>
#include <fstream>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main() {
    std::string folderPath = "exe";

    std::string outputFileName = "combined.exe";

    std::ofstream outputFile(outputFileName, std::ios::binary);

    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".exe") {
            files.push_back(entry.path().string());
        }
    }

    for (const auto& file : files) {
        std::ifstream inputFile(file, std::ios::binary);

        outputFile << inputFile.rdbuf();

        inputFile.close();
    }

    outputFile.close();

    std::cout << "Исполняемые файлы успешно объединены в один файл '" << outputFileName << "'." << std::endl;

    return 0;
}
