#include "string.h"


String::String()
{
    std::string line;
    std::ifstream fin("stdfile.txt");
    while (std::getline(fin, line)) {
        this->string[].push_back(line + ' ');
    }
    for (int i = 0; i < string.size(); i++){
        std::cout << string[i]<<std::endl;
    }
    fin.close();
}

int String::find()
{
    std::string m;
    std::vector < std::vector<std::string> > underline;
    std::cout << "¬ведите подстроку которую ищите>>";
    std::getline(std::cin, m);
    underline.push_back(m);
    for (int i = 0; i < string.size(); i++) {
        if (string[i] == underline[0]) {
            std::cout << "As";
        }
    }
    return 0;
}
