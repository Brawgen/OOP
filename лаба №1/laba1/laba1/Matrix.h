#include <math.h>
#include <iostream>

class Matrix
{
private:
	double matrix;
public:
	Matrix(); //����������� �� ���������
	Matrix& operator=(const Matrix& var) = default; //�������� ������������, ������ � �������� ������ default (���������� ������� ����������� ����)
	~Matrix() = default;

	double pechat();
};