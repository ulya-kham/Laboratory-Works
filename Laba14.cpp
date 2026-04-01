#include <iostream>
#include <limits>
#include <string>
#include "assoc2.h"
#include "assoc17.h"
#include "assoc21.h"
int get_int(const std::string& prompt = "", int min = 0, int max = 4) {//ввод с проверкой от дурака 
    int value;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            else {
                std::cout << "\n\tОшибочка( выбери от " << min << " до " << max << "!\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int main() {//главня функция
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа №14 ~~\n\n";
        std::cout << "\t1. Задание 1 - STL5Assoc2\n";
        std::cout << "\t2. Задание 2 - STL5Assoc17\n";
        std::cout << "\t3. Задание 3 - STL5Assoc21\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        choice = get_int("\n\tВыбери задание: ", 0, 3);
        system("cls");
        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: std::cout << "\n\tМожешь не возвращаться) Пока-пока))\n\n"; break;
        }
        if (choice != 0) {
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            system("cls");
        }
    } while (choice != 0);
    return 0;
}