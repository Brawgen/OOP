#include "Matrix.h"

void Matrix::setitem(int rows, int cols, double value) {
	this->matrix[rows][cols] = value;
}

double Matrix::getitem(int Rows, int Cols)
{
	return matrix[Rows][Cols];
}

Matrix::Matrix() : matrix(0) // способ инициализации полей
{
	std::cout << "¬ведите число строк:";
	std::cin >> rows;
	matrix.resize(rows);
	std::cout << "¬ведите число стобцов:";
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

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrix[i].resize(cols);
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

Matrix Matrix::multiplication_by_number()
{
	this->rows;
	this->cols;
	std::cout << "¬ведите число на которое хотите умножить матрицу:";
	double pr;
	std::cin >> pr;
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result.setitem(i, j, matrix[i][j] * pr);
		}
	}
	return result;
}

Matrix Matrix::transp()
{
	Matrix result(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result.setitem(j, i, matrix[i][j]);
		}
	}
	return result;
}

double  Matrix::det()
{
	if (cols == 1 and rows == 1) {
		std::cout << matrix[0][0];
	}
	if (cols == 2 and rows == 2) {
		std::cout << (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	if (cols > 2 and rows > 2 and cols == rows) {
		double deter = 0;
		for (int i = 0; i < cols; i++) {
			int sign = 1;
			if (i % 2 == 1) {
				sign = -1;
				std::vector<std::vector<double>> Detr(cols - 1, std::vector<double>(cols - 1));
				Detr = Minor(i, 0, Detr);
				deter = deter + sign * Det[0][i] * Deter(cols - 1, Detr);

			}
		}
		return deter;
	}
	
}

std::vector<std::vector<double>> Matrix::Minor(int line, int column, std::vector<std::vector<double>> matr) {
	std::vector < std::vector <double> > Min(matrix.size() - 1, std::vector<double>(matrix.size() - 1));
	for (int i =0; i<m)
}


//void Matrix::multiplication_by_matrix(std::vector< std::vector<double>> mat1, std::vector< std::vector<double>> mat2 )
//{
//	if (mat1.size() == mat2[0].size()) {
//		std::vector< std::vector<double>> mat3;
//		mat3.resize(mat1.size());
//		for (int i = 0; i < mat1.size(); i++) {
//			mat3[i].resize(mat2[0].size());
//		}
//		for (int i = 0; i < mat1.size(); i++) {
//			for (int j = 0; j < mat2[0].size(); j++) {
//				for (int t = 0; t < mat1.size(); t++) {
//					mat3[i][j] += mat1[i][t] * mat2[t][j];
//				}
//			}
//		}
//		for (int i = 0; i < mat3.size(); i++) {
//			for (int j = 0; j < mat3[0].size(); j++) {
//				std::cout << matrix[i][j] << " ";
//			}
//			std::cout << "\n";
//		}
//	}
//}


