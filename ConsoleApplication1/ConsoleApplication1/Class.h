#pragma once
#include <iostream>
#include <vector>
class Matrix
{
private:
    int Rows, Cols;
    std::vector<std::vector<double>> arr;
    void setitem(int Rows, int Cols, double value);
public:
    Matrix();
    Matrix(int Rows, int Cols);
    Matrix(int Rows, int Cols, std::vector<std::vector<double>> arr);
    ~Matrix();
    int getrows()const;
    int getcols()const;
    double getitem(int Rows, int Cols);
    void print();
    Matrix multiplying_by_a_number(double num);
    Matrix transpose();
    Matrix inversion();
    double Determinant();
};