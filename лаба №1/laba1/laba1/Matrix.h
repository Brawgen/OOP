#include <math.h>
#include <iostream>
#include <vector>

class Matrix
{
private:
	int rows, cols;
	std::vector<std::vector<double>> matrix;
public:
	Matrix(); //����������� �� ���������
	Matrix& operator=(const Matrix& var) = default; //�������� ������������, ������ � �������� ������ default (���������� ������� ����������� ����)
	~Matrix() = default;

	std::vector< std::vector<double>> getMatrix();
	void print();
	void multiplication_by_number(); 
	void multiplication_by_matrix();
};