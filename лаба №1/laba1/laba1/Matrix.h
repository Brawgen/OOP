#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

class Matrix
{
public:
	Matrix(std::vector < std::vector <double>> vect);																//Конструктор принимающий вектор
	Matrix(std::string FileName);																					//Конструктор принимающий имя файла для создания матрицы
	Matrix& operator=(const Matrix& other) = default;																//Оператор копирование (перегрузка)
	Matrix() = default;																								//Дефолтный конструктор
	Matrix(const Matrix& Mat_1);																					//Конструктор копирования

	bool operator==(const Matrix& other);
	void print();																									//Метод выводящий в консоль матрицу
	Matrix Multiplication(double a);																				//Метод умножения матрицы на число
	Matrix Multiplication(Matrix multi);																			//Метод умножения матрицы на матрицу
	Matrix Transpose();																								//Метод транспонироания матрицы
	double Deter();																									//Метод нахождения определителя матрицы
	Matrix Reverse_Mat();																							//Метод нахождения обратной матрицы
	void FileWrite(std::string NameFile);																			//Метод записи матрицы в файл txt
	void TableWrite(std::string NameFile);																			//Медот записи матрицы в файл csv (таблица)


	~Matrix() = default;																							//Стандартный деструктор
private:
	int line = 0;																									//Количество строк в матрице
	int column = 0;																									//Количество столбцов в матрице
	std::vector < std::vector <double> > matr;																		//Матрица

	double Deter(int size, std::vector < std::vector <double> > Det);												//Рекурсивный метод для нахождения опреденителя (внутренний)
	std::vector < std::vector <double> > Minor(int line, int colomn, std::vector < std::vector <double>> vect);		//Метод для нахождения миноров матрицы
};