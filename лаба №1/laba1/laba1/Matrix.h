#include <math.h>
#include <iostream>

class Matrix
{
private:
	double matrix;
public:
	Matrix(); //конструктор по умолчанию
	Matrix& operator=(const Matrix& var) = default; //оператор присваивания, пример с ключевым словом default (осуществит битовое копирование поле)
	~Matrix() = default;

	double pechat();
};