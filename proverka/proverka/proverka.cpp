#include "Matrix.h"

int main()
{
	system("chcp 1251 >> null");
	Matrix Mat_1("Matrix_1.txt");
	Matrix Mat_2("Matrix_2.txt");
	Matrix Multi;
	Matrix Mat_ans;

	std::cout << "Матрица_1: " << "\n";
	Mat_1.Show();
	std::cout << "\n" << "\n" << "\n";
	std::cout << "Матрица_2: " << "\n";
	Mat_2.Show();
	std::cout << "\n" << "\n" << "\n";

	if (Mat_1 == Mat_2)
	{
		std::cout << "Матрицы равны!";
	}
	else
	{
		std::cout << "Матрицы не равны!!!";
	}
	std::cout << "\n" << "\n" << "\n";


	std::cout << "Матрица_1  * 3.2 = " << "\n";
	Multi = Mat_1.Multiplication(3.2);
	Multi.Show();
	std::cout << "\n" << "\n" << "\n";

	double deter_1;
	double deter_2;
	std::cout << "Определитель Матрицы_1 = " << "\n";
	deter_1 = Mat_1.Deter();
	std::cout << deter_1 << "\n";
	std::cout << "\n" << "\n" << "\n";
	std::cout << "Определитель Матрицы_2 = " << "\n";
	deter_2 = Mat_2.Deter();
	std::cout << deter_2 << "\n";
	std::cout << "\n" << "\n" << "\n";

	std::cout << "Произедение матриц (Матрица_1 * Матрица_2) = " << "\n";
	Mat_ans = Mat_1.Multiplication(Mat_2);
	Mat_ans.Show();
	std::cout << "\n" << "\n" << "\n";
	std::cout << "Обратная матрица произведения = " << "\n";
	Mat_ans = Mat_ans.Reverse_Mat();
	Mat_ans.Show();
	std::cout << "\n" << "\n" << "\n";

	Mat_ans.FileWrite("Mat_ans.txt");
	Mat_ans.TableWrite("Mat_ans.csv");
}