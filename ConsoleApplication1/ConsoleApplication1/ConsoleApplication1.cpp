// lab 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Class.h"

int main() {
    system("color F0");
    setlocale(LC_ALL, "RUSSIAN");
    Matrix My_matrix;
    if ((My_matrix.getrows() != 0) && (My_matrix.getcols() != 0)) {
        std::cout << "Ваша матрица успешно считана!" << std::endl;
        My_matrix.print();
        std::cout << "Список команд:" << std::endl;
        std::cout << "print_matrix - показать матрицу" << std::endl;
        std::cout << "get_matrix - считать матрицу заново" << std::endl;
        std::cout << "multiplying_by_a_number - умножить матрицу на число" << std::endl;
        std::cout << "transpose - транспонировать матрицу" << std::endl;
        std::cout << "inversion - найти обратную матрицу" << std::endl;
        std::cout << "determinant - найти определитель" << std::endl;
        std::cout << "finish - закончить" << std::endl;
        std::string command = "";
        std::cout << "Введите команду: ";
        std::cin >> command;
        while (command != "finish") {
            if (command == "print_matrix") {
                My_matrix.print();
            }
            else if (command == "get_matrix") {
                Matrix New_matrix;
                My_matrix = New_matrix;
                My_matrix.print();
            }
            else if (command == "multiplying_by_a_number") {
                int num = 0;
                std::cout << "Введите число: ";
                std::cin >> num;
                My_matrix = My_matrix.multiplying_by_a_number(num);
                My_matrix.print();
            }
            else if (command == "transpose") {
                My_matrix = My_matrix.transpose();
                My_matrix.print();
            }
            else if (command == "inversion") {
                if (My_matrix.getrows() == My_matrix.getcols()) {
                    My_matrix = My_matrix.inversion();
                    My_matrix.print();
                }
                else {
                    std::cout << "А матрица то не квадратная!" << std::endl;
                }
            }
            else if (command == "determinant") {
                if (My_matrix.getrows() == My_matrix.getcols()) {
                    double d = My_matrix.Determinant();
                    std::cout << "Куда хотите вывести определитель?" << std::endl;
                    std::cout << "Ваши варианты" << std::endl;
                    std::cout << "В консоль - console" << std::endl;
                    std::cout << "В txt файл - txt" << std::endl;
                    std::cout << "В csv файл - csv" << std::endl;
                    std::string out = "";
                    std::cout << "Введите команду: ";
                    std::cin >> out;
                    if (out == "console") {
                        std::cout << d << std::endl;
                    }
                    else if (out == "txt") {
                        std::string path;
                        std::cout << "Введите путь(куда записываем?): ";
                        std::cin >> path;
                        std::ofstream Write_txt(path, std::ios::app);
                        Write_txt << d << std::endl;
                        Write_txt.close();
                    }
                    else if (out == "csv") {
                        std::string path;
                        std::cout << "Введите путь(куда записываем?): ";
                        std::cin >> path;
                        std::ofstream Write_csv(path, std::ios::app);
                        Write_csv << d << std::endl;
                        Write_csv.close();
                    }
                }
                else {
                    std::cout << "А матрица то не квадратная!" << std::endl;
                }
            }
            else {
                std::cout << "Нет такой команды!" << std::endl;
            }
            std::cout << "Введите команду: ";
            std::cin >> command;
        }
    }
    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
