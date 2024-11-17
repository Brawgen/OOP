#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MyString.h"

int main()
{
    setlocale(LC_ALL, "ru");
    MyString as("stdfile.txt");
    MyString SA("stdfile1.txt");
    as.Show();
    int l = as.Find(SA);
    std::cout << l;

}
