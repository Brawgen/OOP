#include <iostream>
#include "complex.h"
#include "Matrix.h"


int main()
{
    setlocale(LC_ALL, "ru");
    /*Complex number(1,67);
    Complex number2(5, 5);

    Complex summ = number + number2;
    Complex summ2 = number + 5;
    Complex summ3 = 5 + number;

    std::cout << number.Re() << " + i*" << number.Im();
    std::cout << "\n" << number2;*/
    Matrix a;
    a.print();
    std::cout << "\n";
    a.Minor(0, 1);

}