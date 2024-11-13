#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
class String
{
public:
	String();
	int find();


private:
	std::vector < std::vector<std::string> > string;
	int size;
};