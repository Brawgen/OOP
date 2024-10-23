#include "Matrix.h"
int main() {
    setlocale(LC_ALL, "ru");
    Matrix Mat_1("Matrix_1.txt");
    Mat_1.print();
    std::cout << "\n\n";
   
    Matrix negative;
    
    negative = Mat_1.negative();
    negative.print();
    std::cout << "\n\n";


    /* Matrix Mat_ans;
    Matrix Mat_2("Matrix_2.txt");
    std::cout << "Матрица 1: " << "\n";
    Mat_1.print();
    std::cout << "\n\n";
    std::cout << "Матрица 2: " << "\n";
    Mat_2.print();
    std::cout << "\n\n";
    std::string command = "";
    do {
        std::cout << "Список команд:" << std::endl;
        std::cout << "1 - сравнение матриц" << std::endl;
        std::cout << "2 - умножение матрицы на число" << std::endl;
        std::cout << "3 - произведение матриц" << std::endl;
        std::cout << "4 - определитель матриц" << std::endl;
        std::cout << "5 - найти обратную матрицу" << std::endl;
        std::cout << "6 - записать результирующую матрицу" << std::endl;
        std::cout << "7 - закончить" << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "1") {
            system("cls");
            if (Mat_1 == Mat_2)
            {
                std::cout << "Матрицы равныю";
            }
            else
            {
                std::cout << "Матрицы не равны.";
            }
            std::cout << "\n\n";
        }
        else if (command == "2") {
            system("cls");
            double pr;
            std::cout << "Введите число на которое хотите умножить матрицу: ";
            std::cin >> pr;
            std::cout << "Матрица 1  * " << pr << " = " << "\n";
            Multi = Mat_1.Multiplication();
            Multi.print();
            std::cout << "\n\n";
        }
        else if (command == "3") {
            system("cls");
            std::cout << "Произедение матриц (Матрица 1 * Матрица 2) = " << "\n";
            Mat_ans = Mat_1.Multiplication(Mat_2);
            Mat_ans.print();
            std::cout << "\n\n";
        }
        else if (command == "4") {
            system("cls");
            double deter_1;
            double deter_2;
            std::cout << "Определитель Матрицы 1 = " << "\n";
            deter_1 = Mat_1.Deter();
            std::cout << deter_1 << "\n";
            std::cout << "\n\n";
            std::cout << "Определитель Матрицы 2 = " << "\n";
            deter_2 = Mat_2.Deter();
            std::cout << deter_2 << "\n";
            std::cout << "\n\n";
        }
        else if (command == "5") {
            system("cls");
            std::cout << "Обратная матрица = " << "\n";
            Mat_ans = Mat_1.Reverse_Mat();
            Mat_ans.print();
            std::cout << "\n\n";
        }
        else if (command == "6") {
            system("cls");
            Mat_ans.FileWrite("Mat_ans.txt");
            Mat_ans.TableWrite("Mat_ans.csv");
            std::cout << "Матрицы успешно записаны.";
            std::cout << "\n\n";
        }
        else if (command == "7") {
            system("pause");
            exit(0);
        }
        else {
            std::cout << "Нет такой команды!" << std::endl;
        }

    } while (1);*/
}


