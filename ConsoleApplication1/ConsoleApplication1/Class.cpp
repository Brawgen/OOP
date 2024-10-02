#include <iostream>
#include <fstream>
#include "Class.h"
//C:\\Users\\User221225\\Desktop\\proga\\laba_1\\input1.txt

//��������������� ��������� << ��� ������ �������
std::ostream& operator<<(std::ostream& stream, Matrix& My_matrix) {
    for (int i = 0; i < My_matrix.getrows(); i++) {
        for (int j = 0; j < My_matrix.getcols(); j++) {
            stream << My_matrix.getitem(i, j) << " ";
        }
        stream << std::endl;
    }
    return stream;
}

//����������� �� ���������
Matrix::Matrix() {
    this->Cols = 0;
    this->Rows = 0;
    std::string path;
    std::cout << "������� ����(������ ���������?): ";
    std::cin >> path;
    std::ifstream in(path);
    if (in.is_open()) {
        //���� �������� ����� ������ �������
        //������� ��������� ������� ����� � �����
        int count = 0; //����� ����� � �����
        int temp; //��������� ����������
        while (!in.eof()) // ��������� ���� �� �������� ����� ����� eof
        {
            in >> temp; //� ������� ��������� �� ����� �����
            count++; //����������� ������� ����� �����
        }
        //����� ����� ���������, ������ ��� ����� ������ ������� ����� � ����� ������
        //��� ����� ��������� ����� �������� �� ����� �������� �� ����� ������
        //������� ��������� ������� � ������ � ������ �����
        in.seekg(0, std::ios::beg);
        in.clear();
        //����� �������� � ������ ������� ������� ����� 0
        int count_space = 0;
        char symbol;
        while (!in.eof()) //�� ������ ������ ���� ������������ ������ �����
        {
            //������ ��� ����� ��������� �� �����, � ����������� ��������� ������
            in.get(symbol); //������� ������� ������
            if (symbol == ' ') count_space++; //���� ��� ������, �� ����� �������� �����������
            if (symbol == '\n') break; //���� ����� �� ����� ������, �� ������� �� �����
        }
        //����� ��������� � ������ � ������ �����
        in.seekg(0, std::ios::beg);
        in.clear();
        //������ �� ����� ������� ����� � ����� � ������� �������� � ������ ������.
        //������ ����� ������� �������.
        this->Rows = count / (count_space + 1); //����� �����;
        this->Cols = count_space + 1; //����� �������� �� ������� ������ ����� ��������;
        this->arr.resize(Rows);
        for (int i = 0; i < Rows; i++) {
            arr[i].resize(Cols);
        }
        //������� ������� �� �����
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) in >> arr[i][j];
        }
        in.close();
    }
    else {
        std::cout << "��������� ������� �������!" << std::endl;
        in.close();
    }
}

//����������� ��� �������� �������������� ������
Matrix::Matrix(int Rows, int Cols) {
    this->Rows = Rows;
    this->Cols = Cols;
    this->arr.resize(Rows);
    for (int i = 0; i < Rows; i++) {
        arr[i].resize(Cols);
    }
}

//����������� �����������
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

//����������
Matrix::~Matrix() {}

//����� ��������� �������� �� ��������
double Matrix::getitem(int Rows, int Cols) {
    return this->arr[Rows][Cols];
}

//����� ��������� �������� �������� �� ��������
void Matrix::setitem(int Rows, int Cols, double value) {
    this->arr[Rows][Cols] = value;
}

//����� ��������� ���������� �����
int Matrix::getrows()const {
    return this->Rows;
}

//����� ��������� ���������� ��������
int Matrix::getcols()const {
    return this->Cols;
}

//����� ������ ������� �� ������ ������������ (�������, txt ����, csv ����)
void Matrix::print() {
    Matrix My_matrix(Rows, Cols, arr);
    std::cout << "���� ������ ������� �������?" << std::endl;
    std::cout << "���� ��������" << std::endl;
    std::cout << "� ������� - console" << std::endl;
    std::cout << "� txt ���� - txt" << std::endl;
    std::cout << "� csv ���� - csv" << std::endl;
    std::string out = "";
    std::cout << "������� �������: ";
    std::cin >> out;
    if (out == "console") {
        std::cout << My_matrix;
    }
    else if (out == "txt") {
        //������� ������� � ����
        std::string path;
        std::cout << "������� ����(���� ����������?): ";
        std::cin >> path;
        std::ofstream Write_txt(path, std::ios::app);
        Write_txt << "��� ���� �������:" << std::endl;
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
        //������� ������� � ����
        std::string path;
        std::cout << "������� ����(���� ����������?): ";
        std::cin >> path;
        std::ofstream Write_csv(path, std::ios::app);
        Write_csv << "��� ���� �������:" << std::endl;
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

//����� ��������� ������� �� �����
Matrix Matrix::multiplying_by_a_number(double num) {
    this->Rows;
    this->Cols;
    Matrix result(Rows, Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) result.setitem(i, j, arr[i][j] * num);
    }
    return result;
}

//����� ���������������� �������
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

//���������� �������� ������� ������� ������
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

//���������� ������������ ������� ������
double Matrix::Determinant() {
    if ((Rows < 1) || (Cols < 1)) {
        std::cout << "�� ������ �������!" << std::endl;
        return 0.0;  // ������������ �������
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
