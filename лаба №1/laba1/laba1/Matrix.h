#pragma once
#include <math.h>
#include <iostream>

class Complex
{
	//¬нутреннее представление
private:
	double realPart;
	double imaginaryPart;

public:
	Complex(); //конструктор по умолчанию
	Complex(const Complex& var); // конструктор копировани
	Complex(double real); //конструктор с параметром из действительного числа
	Complex(double re, double im); // конструктор с параметром из пары чисел

	Complex& operator=(const Complex& var) = default; //оператор присваивани€, пример с ключевым словом default (осуществит битовое копирование поле)

	~Complex() = default; //ƒеструктор, пример с ключевым словом default (будет пустой)

	double Re(); //метод возвращающий реальную часть
	double Im(); //метод возвращающий мимую часть
	double magnitude(); // метод вычисл€ющий модуль числа
	double angle(); // метод вычисл€ющий аргумент числа

	Complex complement(); // метод возвращающий сопр€щенное число

	Complex operator+(const Complex& var); // перегруженный оператор сложени€ ј + ¬
	Complex operator+(const double& var); // перегруженный оператор сложени€ комплексного и действительного ј + b
	friend Complex operator+(const double& var1, const Complex& var2); //перегруженный оператор сложени€ а + ¬, дружественна€ функци€

	Complex operator*(const Complex& var); // умножение ј*¬
	Complex operator*(const double& var); // умножение ј*b
	friend Complex operator*(const double& var1, const Complex& var2); //”множение а*¬

	friend std::ostream& operator<<(std::ostream& s, const Complex& c); //перегрузка оператора потокового вывода
};