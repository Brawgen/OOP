#include "string.h"




String::String()
{
    std::string line;
    std::ifstream fin("stdfile.txt");
    while (std::getline(fin, line)) {
        this->string.push_back(line);
    }
    for (int i = 0; i < string.size(); i++) {
        std::cout << string[i];
    }
    fin.close();
}
