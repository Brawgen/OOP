#include "Matrix.h"


Matrix::Matrix() : matrix(0) // ������ ������������� �����
{
	std::cout << "������� ����� �����:";
	std::cin >> rows;
	matrix.resize(rows);
	std::cout << "������� ����� �������:";
	std::cin >> cols;
	for (int i = 0; i < rows; i++) {
			matrix[i].resize(cols);

		}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}


std::vector< std::vector<double>> Matrix::getMatrix()
{
	return matrix;
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Matrix::multiplication_by_number()
{
	std::cout << "������� ����� �� ������� ������ �������� �������:";
	double pr;
	std::cin >> pr;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j]= matrix[i][j] * pr;
		}
	}
}

void Matrix::multiplication_by_matrix(std::vector< std::vector<double>> mat1, std::vector< std::vector<double>> mat2 )
{
	std::vector< std::vector<double>> mat3 = mat1 * mat2;
}


