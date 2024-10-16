#include <math.h>
#include <iostream>
#include <vector>

class Matrix
{
private:
	int rows, cols;
	std::vector<std::vector<double>> matrix;
	void setitem(int Rows, int Cols, double value);
	double getitem(int Rows, int Cols);
public:
	Matrix(); //конструктор по умолчанию
	Matrix(int rows, int cols);
	Matrix& operator=(const Matrix& var) = default; //оператор присваивания, пример с ключевым словом default (осуществит битовое копирование поле)
	~Matrix() = default;

	std::vector< std::vector<double>> getMatrix();
	void print();
	Matrix multiplication_by_number(); 
	//Matrix multiplication_by_matrix(std::vector< std::vector<double>> mat1, std::vector< std::vector<double>> mat2);
	Matrix transp();
	double det(int size, std::vector<std::vector<double>> matrix);
	double det();
	std::vector<std::vector<double>> Minor(int line, int column);
};