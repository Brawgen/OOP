#include <iostream>
#include <fstream>
#include "Class.h"
//C:\\Users\\User221225\\Desktop\\proga\\laba_1\\input1.txt

//Переопределение опреатора << для вывода матрицы
std::ostream& operator<<(std::ostream& stream, Matrix& My_matrix) {
    for (int i = 0; i < My_matrix.getrows(); i++) {
        for (int j = 0; j < My_matrix.getcols(); j++) {
            stream << My_matrix.getitem(i, j) << " ";
        }
        stream << std::endl;
    }
    return stream;
}

//Конструктор по умолчанию
Matrix::Matrix() {
    this->Cols = 0;
    this->Rows = 0;
    std::string path;
    std::cout << "Введите путь(откуда считываем?): ";
    std::cin >> path;
    std::ifstream in(path);
    if (in.is_open()) {
        //Если открытие файла прошло успешно
        //Вначале посчитаем сколько чисел в файле
        int count = 0; //число чисел в файле
        int temp; //Временная переменная
        while (!in.eof()) // пробегаем пока не встретим конец файла eof
        {
            in >> temp; //в пустоту считываем из файла числа
            count++; //увеличиваем счетчик числа чисел
        }
        //Число чисел посчитано, теперь нам нужно понять сколько чисел в одной строке
        //Для этого посчитаем число пробелов до знака перевода на новую строку
        //Вначале переведем каретку в потоке в начало файла
        in.seekg(0, std::ios::beg);
        in.clear();
        //Число пробелов в первой строчке вначале равно 0
        int count_space = 0;
        char symbol;
        while (!in.eof()) //на всякий случай цикл ограничиваем концом файла
        {
            //теперь нам нужно считывать не числа, а посимвольно считывать данные
            in.get(symbol); //считали текущий символ
            if (symbol == ' ') count_space++; //Если это пробел, то число пробелов увеличиваем
            if (symbol == '\n') break; //Если дошли до конца строки, то выходим из цикла
        }
        //Опять переходим в потоке в начало файла
        in.seekg(0, std::ios::beg);
        in.clear();
        //Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
        //Теперь можем считать матрицу.
        this->Rows = count / (count_space + 1); //число строк;
        this->Cols = count_space + 1; //число столбцов на единицу больше числа пробелов;
        this->arr.resize(Rows);
        for (int i = 0; i < Rows; i++) {
            arr[i].resize(Cols);
        }
        //Считаем матрицу из файла
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) in >> arr[i][j];
        }
        in.close();
    }
    else {
        std::cout << "Неудалось считать матрицу!" << std::endl;
        in.close();
    }
}

//Конструктор для создания результирующих матриц
Matrix::Matrix(int Rows, int Cols) {
    this->Rows = Rows;
    this->Cols = Cols;
    this->arr.resize(Rows);
    for (int i = 0; i < Rows; i++) {
        arr[i].resize(Cols);
    }
}

//Конструктор копирования
Matrix::Matrix(int Rows, int Cols, std::vector<std::vector<double>> arr_w) {
    this->Rows = Rows;
    this->Cols = Cols;
    this->arr.resize(Rows);
    for (int i = 0; i < Rows; i++) {
        arr[i].resize(Cols);
    }
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = arr_w[i][j];
        }
    }
}

//Деструктор
Matrix::~Matrix() {}

//Метод получения элемента по индексам
double Matrix::getitem(int Rows, int Cols) {
    return this->arr[Rows][Cols];
}

//Метод установки значения элемента по индексам
void Matrix::setitem(int Rows, int Cols, double value) {
    this->arr[Rows][Cols] = value;
}

//Метод получения количества строк
int Matrix::getrows()const {
    return this->Rows;
}

//Метод получения количества столбцов
int Matrix::getcols()const {
    return this->Cols;
}

//Метод вывода матрицы по выбору пользователя (консоль, txt файл, csv файл)
void Matrix::print() {
    Matrix My_matrix(Rows, Cols, arr);
    std::cout << "Куда хотите вывести матрицу?" << std::endl;
    std::cout << "Ваши варианты" << std::endl;
    std::cout << "В консоль - console" << std::endl;
    std::cout << "В txt файл - txt" << std::endl;
    std::cout << "В csv файл - csv" << std::endl;
    std::string out = "";
    std::cout << "Введите команду: ";
    std::cin >> out;
    if (out == "console") {
        std::cout << My_matrix;
    }
    else if (out == "txt") {
        //Выведем матрицу в файл
        std::string path;
        std::cout << "Введите путь(куда записываем?): ";
        std::cin >> path;
        std::ofstream Write_txt(path, std::ios::app);
        Write_txt << "Вот ваша матрица:" << std::endl;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                Write_txt << arr[i][j] << " ";
                Write_txt << std::endl;
            }
            Write_txt << std::endl;
        }
        Write_txt << std::endl;
        Write_txt.close();
    }
    else if (out == "csv") {
        //Выведем матрицу в файл
        std::string path;
        std::cout << "Введите путь(куда записываем?): ";
        std::cin >> path;
        std::ofstream Write_csv(path, std::ios::app);
        Write_csv << "Вот ваша матрица:" << std::endl;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                Write_csv << arr[i][j] << ";";
            }
            Write_csv << std::endl;
        }
        Write_csv << std::endl;
        Write_csv.close();
    }
}

//Метод умножения матрицы на число
Matrix Matrix::multiplying_by_a_number(double num) {
    this->Rows;
    this->Cols;
    Matrix result(Rows, Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) result.setitem(i, j, arr[i][j] * num);
    }
    return result;
}

//Метод транспонирования матрицы
Matrix Matrix::transpose() {
    this->Rows;
    this->Cols;
    Matrix result(Cols, Rows);
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.setitem(j, i, this->arr[i][j]);
        }
    }
    return result;
}

//Нахождение обратной матрицы методом Гаусса
Matrix Matrix::inversion() {
    this->Rows;
    this->Cols;
    Matrix result(Rows, Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            result.setitem(i, j, arr[i][j]);
        }
    }
    double temp;
    double** E = new double* [Cols];
    for (int i = 0; i < Cols; i++) {
        E[i] = new double[Cols];
    }
    for (int i = 0; i < Cols; i++) {
        for (int j = 0; j < Cols; j++) {
            E[i][j] = 0.0;
            if (i == j)
                E[i][j] = 1.0;
        }
    }
    for (int k = 0; k < Cols; k++) {
        temp = arr[k][k];
        for (int j = 0; j < Cols; j++) {
            arr[k][j] /= temp;
            E[k][j] /= temp;
        }
        for (int i = k + 1; i < Cols; i++) {
            temp = arr[i][k];
            for (int j = 0; j < Cols; j++) {
                arr[i][j] -= arr[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (int k = Cols - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            temp = arr[i][k];
            for (int j = 0; j < Cols; j++) {
                arr[i][j] -= arr[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (int i = 0; i < Cols; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = E[i][j];
        }
    }
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) result.setitem(i, j, arr[i][j]);
    }
    for (int i = 0; i < Cols; i++) {
        delete[] E[i];
    }
    delete[] E;
    return result;
}

//Нахождение определителя методом Гаусса
double Matrix::Determinant() {
    if ((Rows < 1) || (Cols < 1)) {
        std::cout << "Не задана матрица!" << std::endl;
        return 0.0;  // Некорректная матрица
    }
    this->arr = arr;
    double** work = new double* [Rows];
    for (int i = 0; i < Rows; i++) {
        work[i] = new double[Rows];
    }
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Rows; j++) work[i][j] = arr[i][j];
    }
    float coef;
    int i;
    for (int k = 0; k < Rows - 1; k++) {
        for (i = k + 1; i < Rows; i++) {
            coef = work[i][k] / work[k][k];
            for (int j = k; j < Rows; j++) {
                work[i][j] = work[i][j] - coef * work[k][j];
            }
        }
    }
    float det = 1;
    for (int i = 0; i < Rows; i++) {
        det = det * float(work[i][i]);
    }
    for (int i = 0; i < Rows; i++) {
        delete[] work[i];
    }
    delete[] work;
    return det;
}
