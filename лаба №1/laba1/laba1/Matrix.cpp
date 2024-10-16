#include "Matrix.h"

void Matrix::setitem(int rows, int cols, double value) {
	this->matrix[rows][cols] = value;
}

double Matrix::getitem(int Rows, int Cols)
{
	return matrix[Rows][Cols];
}

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
	std::cout << "������� ����� �� ������� ������ �������� �������:";
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

double  Matrix::det(int size, std::vector<std::vector<double>> matrix)
{
	double deter = 0;
	if (size == 1 ) {
		deter= matrix[0][0];
	}
	if (size == 2) {
		deter= (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	if (size>2) {
		for (int i = 0; i < size; i++)
		{
			int sign = 1;
			if (i % 2 == 1)
			{
				sign = -1;
			}
			std::vector < std::vector <double> > Detr(size - 1, std::vector<double>(size - 1));
			//Detr = Minor(0, i, matrix);
			deter = deter + sign * matrix[0][i] * det(size-1,Detr);
		}
	}
	return deter;
}
double Matrix::det()
{
	if (cols != rows) {
		std::cout << "������� �� ����������!";
		exit(0);
	}
	else {
		double deter;
		deter = det(cols,matrix);
		return deter;
	}
}

std::vector<std::vector<double>> Matrix::Minor(int line, int column)
{
	int Rows = this->rows;
	int Cols = this->cols;
	std::vector<std::vector<double>> minor(Rows - 1, std::vector<double>(Cols - 1));
	
	for (int i = 0; i < Rows - 1; i++) {
		for (int j = 0; j < Cols - 1; j++) {
			bool flag1 = false;
			bool flag2 = false;
			
			if (i == line) {
				flag1 = true;
			}
			if (j == column) {
				flag2 = true;
			}
			if (flag1 == false) {
				minor[i][j] = matrix[i][j];
			}
			if (flag1 == true and flag2==false) {
				minor[i][j] = matrix[i + 1][j];
			}
			if (flag1==false and flag2 == true) {
				minor[i][j] = matrix[i][j + 1];
			}
			if (flag2 == true and flag1 == true) {
				minor[i][j] = matrix[i + 1][j + 1];
			}
		}
	}
	for (int i = 0; i < Rows-1; i++) {
		for (int j = 0; j < Cols-1; j++) {
			std::cout << minor[i][j] << " ";
		}
		std::cout << "\n";
	}
	return minor;
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


