#include <iostream>
#include <string>
#include <algorithm>

void reverseSubstring(std::string& text, int start, int end) {
    // Проверка корректности диапазона
    if (start < 0|| end >= static_cast<int>(text.size()) || start > end) {
        std::cerr << "Ошибка: некорректный диапазон!" << std::endl;
        return;
    }
    // Переворот диапазона
    std::reverse(text.begin() + start, text.begin() + end + 1);
}

int main() {
    setlocale(LC_ALL, "ru");
    std::string text;
    int start, end;

    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    std::cout << "Введите начало диапазона: ";
    std::cin >> start;

    std::cout << "Введите конец диапазона: ";
    std::cin >> end;

    reverseSubstring(text, start, end);

    std::cout << "Результат: " << text << std::endl;

    return 0;
}