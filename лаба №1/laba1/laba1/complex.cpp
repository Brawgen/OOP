#include "Complex.h"

Complex::Complex() : realPart(0), imaginaryPart(0) // способ инициализации полей
{
}

Complex::Complex(const Complex& var)
{
	//дргуой способ инициализации полей
	this->realPart = var.realPart; //this - это указатель на объект дл€ которого будет вызван метод
	this->imaginaryPart = var.imaginaryPart;
}

Complex::Complex(double real)
{
	this->realPart = real;
	this->imaginaryPart = 0;
}

Complex::Complex(double re, double im)
{
	this->imaginaryPart = im;
	this->realPart = re;

}

double Complex::Re()
{
	return realPart;
}

double Complex::Im()
{
	return imaginaryPart;
}

double Complex::magnitude()
{
	return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
}

double Complex::angle()
{
	return atan2(realPart, imaginaryPart);
}

Complex Complex::complement()
{
	return Complex(this->realPart, -this->imaginaryPart); //экземпл€ры могут пораждать экземпл€ры того же класса
}

Complex Complex::operator+(const Complex& var)
{

	double realPart = this->realPart + var.realPart;
	double imaginaryPart = this->imaginaryPart + var.imaginaryPart;
	return Complex(realPart, imaginaryPart);
}

Complex Complex::operator+(const double& var)
{
	return Complex(this->realPart + var, this->imaginaryPart);
}

Complex Complex::operator*(const Complex& var)
{
	double realPart = this->realPart * var.realPart - this->imaginaryPart * var.imaginaryPart;
	double imaginaryPart = this->realPart * var.imaginaryPart - this->imaginaryPart * var.realPart;
	return Complex(realPart, imaginaryPart);
}

Complex Complex::operator*(const double& var)
{
	return Complex(this->realPart * var, this->imaginaryPart * var);
}

Complex operator+(const double& var1, const Complex& var2)
{
	return Complex(var1 + var2.realPart, var2.imaginaryPart);
}

Complex operator*(const double& var1, const Complex& var2)
{
	return Complex(var1 * var2.realPart, var1 * var2.imaginaryPart);
}

std::ostream& operator<<(std::ostream& s, const Complex& c)
{

	s << c.realPart << " + i*" << c.imaginaryPart;

	return s; // функци€ должна возвращать поток, чтобы иметь возможность делать std::cout << 1 << 2 << 3,
	//иначе можно будет делать только std::cout << 1; std::cout << 2; std::cout << 3;
}
