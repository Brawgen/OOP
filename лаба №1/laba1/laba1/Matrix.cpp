#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<double>> vect)
{
	int line = vect.size();
	int column = vect[0].size();
	this->matr.resize(line, std::vector<double>(column));
	this->line = line;
	this->column = column;
	this->matr = vect;
}

Matrix::Matrix(std::string FileName)
{
	std::ifstream file(FileName);
	if (file.is_open())
	{
		std::string str;
		bool first_line = 1;
		bool security = 1;

		while (std::getline(file, str))
		{
			std::istringstream flow(str);
			std::vector<double> rows;
			double value;

			while (flow >> value)
			{
				rows.push_back(value);
			}
			if (first_line)
			{
				column = rows.size();
				first_line = 0;
			}
			if (rows.size() == column)
			{
				matr.push_back(rows);
			}
			else
			{
				std::cout << "Ошибка.";
				security = 0;
			}
		}
		this->line = matr.size();
		if (matr.size() > 0)
		{
			this->column = matr[0].size();
		}
		if (security == 0)
		{
			matr.clear();
			this->line = 0;
			this->column = 0;
		}
		file.close();
	}
	else
	{
		std::cout << "Ошибка чтения файла." << "\n";
		system("pause");
		exit(0);
	}
}

Matrix::Matrix(const Matrix& Mat_1)
{
	this->matr = Mat_1.matr;
	this->line = Mat_1.line;
	this->column = Mat_1.column;
}

bool Matrix::operator==(const Matrix& other)
{
	if ((this->column != other.column) or (this->line != other.line))
	{
		return false;
	}
	for (int i = 0; i < this->line; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			if (this->matr[i][j] != other.matr[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Matrix::print()			//Показать матрицу
{
	for (int i = 0; i < this->line; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			std::cout << this->matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

Matrix Matrix::Multiplication(double a) //Умножение матрицы на число
{
	std::vector < std::vector <double> > Multi_vect(this->line, std::vector<double>(this->column));
	for (int i = 0; i < this->line; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			Multi_vect[i][j] = (a * (this->matr[i][j]));
		}
	}
	Matrix Multi_matr(Multi_vect);
	return Multi_matr;
}



Matrix Matrix::Multiplication(Matrix multi) //Умножение матрицы на матрицу
{
	if ((this->column != multi.line) or (this->column == 0) or (this->line == 0) or (multi.line == 0) or (multi.column == 0))
	{
		std::cout << "Ошибка умножения матриц." << "\n";
		Matrix empty;
		return empty;
	}
	line = this->line;
	int l = this->column;
	column = multi.column;
	std::vector < std::vector <double> > Vect(line, std::vector<double>(column));
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			Vect[i][j] = 0;
			for (int k = 0; k < l; k++)
			{
				Vect[i][j] = Vect[i][j] + (this->matr[i][k] * multi.matr[k][j]);
			}

		}
	}
	Matrix Multi_matr(Vect);
	return Multi_matr;
}

Matrix Matrix::Transpose()		//Транспонирование
{
	if ((this->line == 0) or (this->column == 0))
	{
		std::cout << "Нельзя транспонировать нулевую матрицу." << "\n";
		Matrix empty;
		return empty;
	}
	std::vector < std::vector <double> > T(this->column, std::vector<double>(this->line));
	for (int i = 0; i < this->line; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			T[j][i] = this->matr[i][j];
		}
	}
	Matrix Tr(T);
	return Tr;
}

double Matrix::Deter(int size, std::vector < std::vector <double> > Det)			//Определитель матрицы
{
	if (size == 1)
	{
		return Det[0][0];
	}
	if (size == 2)
	{
		return ((Det[0][0] * Det[1][1]) - (Det[1][0] * Det[0][1]));
	}
	double deter = 0;
	for (int i = 0; i < size; i++)
	{
		int sign = 1;
		if (i % 2 == 1)
		{
			sign = -1;
		}
		std::vector < std::vector <double> > Detr(size - 1, std::vector<double>(size - 1));
		Detr = Minor(i, 0, Det);
		deter = deter + sign * Det[0][i] * Deter(size - 1, Detr);
	}
	return deter;
}

double Matrix::Deter()					//Проверка на квадратную матрицу и вызов функции для нахождения опрделителя вектора
{
	if ((this->column != this->line) or (this->line == 0))
	{
		std::cout << "Невозможно найти определитель. Матрица не квадратная или нулевая." << "\n";
		return NAN;
	}
	double Det;
	Det = Deter(this->column, this->matr);
	return Det;
}

std::vector<std::vector<double>> Matrix::Minor(int line, int column, std::vector<std::vector<double>> matr)  //Нахождение миноров матрицы
{
	int size = matr.size();
	std::vector < std::vector <double> > Min(size - 1, std::vector<double>(size - 1));
	for (int j = 0; j < size - 1; j++)
	{
		int shift_c = 0;
		if (j >= column)
		{
			shift_c = 1;
		}
		for (int k = 0; k < size - 1; k++)
		{
			int shift_l = 0;
			if (k >= line)
			{
				shift_l = 1;
			}
			Min[j][k] = matr[j + shift_c][k + shift_l];
		}
	}
	return Min;
}

Matrix Matrix::Reverse_Mat()
{
	if ((this->column != this->line) or (this->line == 0))
	{
		std::cout << "Невозможно найти обратную матрицу. Матрица не квадратная или нулевая.";
		Matrix empty;
		return empty;
	}
	int size = this->line;
	std::vector < std::vector <double> > Rev_mat(size, std::vector<double>(size));
	std::vector < std::vector <double> > Min(size - 1, std::vector<double>(size - 1));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int sign = 1;
			if ((i + j) % 2 == 1)
			{
				sign = -1;
			}
			Min = Minor(j, i, this->matr);
			Rev_mat[i][j] = (sign * Deter(size - 1, Min));
		}
	}
	Matrix Reverse(Rev_mat);
	Reverse = Reverse.Transpose();
	double det = Deter(size, this->matr);
	Reverse = Reverse.Multiplication(1 / det);
	return Reverse;
}

void Matrix::FileWrite(std::string NameFile)
{
	setlocale(LC_ALL, " ");
	std::ofstream File;
	File.open(NameFile);

	if (File.is_open())
	{
		for (int i = 0; i < this->line; i++)
		{
			for (int j = 0; j < this->column; j++)
			{
				File << this->matr[i][j];
				File << " ";
			}
			File << "\n";
		}
		File.close();
	}
	else
	{
		std::cout << "Ошибка чтения файла." << "\n";
		system("pause");
		exit(0);
	}
	return;
}

void Matrix::TableWrite(std::string NameFile)
{
	setlocale(LC_ALL, " ");
	std::ofstream File;
	File.open(NameFile);

	if (File.is_open())
	{
		for (int i = 0; i < this->line; i++)
		{
			for (int j = 0; j < this->column; j++)
			{
				File << this->matr[i][j];
				File << ";";
			}
			File << "\n";
		}
		File.close();
	}
	else
	{
		std::cout << "Ошибка чтения файла." << "\n";
		system("pause");
		exit(0);
	}
	return;
}

