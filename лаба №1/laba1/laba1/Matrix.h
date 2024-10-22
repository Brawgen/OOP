#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

class Matrix
{
public:
	Matrix(std::vector < std::vector <double>> vect);																//����������� ����������� ������
	Matrix(std::string FileName);																					//����������� ����������� ��� ����� ��� �������� �������
	Matrix& operator=(const Matrix& other) = default;																//�������� ����������� (����������)
	Matrix() = default;																								//��������� �����������
	Matrix(const Matrix& Mat_1);																					//����������� �����������

	bool operator==(const Matrix& other);
	void print();																									//����� ��������� � ������� �������
	Matrix Multiplication(double a);																				//����� ��������� ������� �� �����
	Matrix Multiplication(Matrix multi);																			//����� ��������� ������� �� �������
	Matrix Transpose();																								//����� ��������������� �������
	double Deter();																									//����� ���������� ������������ �������
	Matrix Reverse_Mat();																							//����� ���������� �������� �������
	void FileWrite(std::string NameFile);																			//����� ������ ������� � ���� txt
	void TableWrite(std::string NameFile);																			//����� ������ ������� � ���� csv (�������)


	~Matrix() = default;																							//����������� ����������
private:
	int line = 0;																									//���������� ����� � �������
	int column = 0;																									//���������� �������� � �������
	std::vector < std::vector <double> > matr;																		//�������

	double Deter(int size, std::vector < std::vector <double> > Det);												//����������� ����� ��� ���������� ������������ (����������)
	std::vector < std::vector <double> > Minor(int line, int colomn, std::vector < std::vector <double>> vect);		//����� ��� ���������� ������� �������
};