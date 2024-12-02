#include "string.h"
#include "MyString.h"


MyString::MyString(std::string filename)
{
	system("chcp 1251 >> null");
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		char buffer;

		while (fin.get(buffer))
		{
			this->String.push_back(buffer);
		}
		fin.close();

	}
	else
	{
		std::cout << "Ошибка чтения файла!" << "\n";
	}
	UnderCase();
}

MyString::MyString(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		this->String.push_back(s[i]);
		i++;
	}
}

void MyString::UnderCase()
{
	for (int i = 0; i < this->String.size(); i++) {
		if ((int(String[i]) > 64) and (int(String[i]) < 91)){
			this->string.push_back(this->String[i] + 32);
		}
		else {
			this->string.push_back(this->String[i]);
		}
	}
}

int MyString::Find(MyString substring)
{
	for (int i = 0; i < this->String.size(); i++) {
		if (substring.String[0] == this->String[i]) {
			int reg = 1;
			for (int j = 1; j < substring.String.size(); j++) {
				if ((substring.String[j] == this->String[i + j]) and (i!= this->String.size()-1)) {
					reg++;
			}
				else {
					break;
				}
				if (reg == substring.String.size()) {
					return i;
				}
			}
		}

	}
	return -1; 
}





void MyString::Show()
{
	for (int i = 0; i < string.size(); i++) {
		std::cout << this->string[i];
	}
	std::cout << '\n';
}
