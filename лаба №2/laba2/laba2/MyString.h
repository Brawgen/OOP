#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
class MyString
{
public:
	MyString(std::string filename);
	MyString(char* s);
	MyString() = default;
	
	void UnderCase();
	int Find(MyString substring);

	void Show();

private:
	std::vector <char> String;
	std::vector <char> string;
	int size;
};