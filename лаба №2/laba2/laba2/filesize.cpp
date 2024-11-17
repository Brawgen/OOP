#include "filesize.h"

int filesize(std::string file_name)
{
    std::ifstream fin(file_name);
    if (fin.is_open()) {
        fin.seekg(0, std::ios::end);
        int size = fin.tellg();
        return size;
    }
    else {
        std::cout << "Ошибка открытия файла.";
        exit(0);
    }
    fin.close();
    
    
}
