#include <math.h>
#include <iostream>
#include <vector>

class Matrix
{
private:
	int rows, cols;
	std::vector<std::vector<double>> matrix;
public:
	Matrix(); //конструктор по умолчанию
	Matrix& operator=(const Matrix& var) = default; //оператор присваивания, пример с ключевым словом default (осуществит битовое копирование поле)
	~Matrix() = default;

	std::vector< std::vector<double>> getMatrix();
	void print();
	void multiplication_by_number(); 
	void multiplication_by_matrix();
};