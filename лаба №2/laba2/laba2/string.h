#pragma once
#include <fstream>
#include <vector>
#include <iostream>
class String
{
public:
	String(std::string FileName);
	String();


	~String() = default;
private:
	std::vector < std::vector <double> > string;
};