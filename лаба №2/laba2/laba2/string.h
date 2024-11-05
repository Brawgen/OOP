#pragma once
#include <fstream>
#include <vector>
#include <iostream>
class String
{
public:
	int filesize();
	String();


	~String() = default;
private:
	std::vector < char > string;
	int size;
};