#include "string.h"


int String::filesize()
{

    std::vector < char > string;
    std::cout << "Сумма цифр слов состоящих только из цифр: ";
    std::ifstream fin("stdfile.txt");
    while (fin.getline(string,size)) {
        std::cout << "" << std::endl;
    }
   /* char stroka;
    std::ifstream fin("stdfile.txt");
    if (fin.is_open()) {
        fin.seekg(0, std::ios::end);
        int size = fin.tellg();
    }
    else {
        std::cout << "Ошибка открытия файла.";
        exit(0);
    }
    this->string.resize(size);
    fin.getline(stroka, size);
    fin.close();
}*/

String::String()
{
	
}
