#include <iostream>
#include <limits>
#include <string>
#include "seq5.h"
#include "seq8.h"
#include "seq34.h"
#include "iter8.h"
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
        std::cout << "\n\t\t~~ Лабораторная работа №12 ~~\n\n";
        std::cout << "\t1. Задание 1 - STL2Seq5\n";
        std::cout << "\t2. Задание 2 - STL2Seq8\n";
        std::cout << "\t3. Задание 3 - STL2Seq34\n";
        std::cout << "\t4. Задание 4 - STL1Iter8\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        choice = get_int("\n\tВыбери задание: ", 0, 4);
        system("cls");
        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
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