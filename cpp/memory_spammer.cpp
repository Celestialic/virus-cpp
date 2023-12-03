#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void setHiddenAttribute(const string& filename) {
#ifdef _WIN32
    SetFileAttributesA(filename.c_str(), FILE_ATTRIBUTE_HIDDEN);
#endif
}

int main() {
    const int numFiles = 100;
    const int fileSizeMB = 25;

    for (int i = 1; i <= numFiles; ++i) {
        string filename = "hidden_file_" + to_string(i) + ".txt";
        ofstream file(filename, ios::out | ios::binary);

        if (file.is_open()) {
            // Set the file size to 25 MB
            file.seekp(fileSizeMB * 1024 * 1024 - 1);
            file.put(0);

            file.close();

            // Set the file as hidden
            setHiddenAttribute(filename);

            cout << "Created hidden file: " << filename << endl;
        } else {
            cerr << "Error creating file: " << filename << endl;
            return 1;
        }
    }

    return 0;
}
