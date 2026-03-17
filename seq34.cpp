#include "seq34.h"
#include "utils.h"
#include <iostream>
#include <list>
#include <vector>
void print_list(const std::list<int>& L) {//вывод чрз итераторы
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
}
void task3() {//задание 3
    std::cout << "\n\t~~ Задание 3 (STL2Seq34) ~~\n\n";
    std::cout << "\tКак заполнить списки?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> input1, input2;//два вектора
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_pos();//n > 0
        std::cout << "\n\t~ Заполняем первый список (A) ~\n";
        fill_vector(input1, method, n);
        std::cout << "\n\t~ Заполняем второй список (B) ~\n";
        fill_vector(input2, method, n);
    }
    else if (method == 3) {
        std::string f1, f2;
        std::cout << "\n\tВведи имя файла для первого списка (A): ";
        std::cin >> f1;
        read_file_vec(f1, input1);
        std::cout << "\n\tВведи имя файла для второго списка (B): ";
        std::cin >> f2;
        read_file_vec(f2, input2);
        if (input1.size() != input2.size() || input1.empty()) {
            std::cout << "\n\tОшибочка( списки должны быть одинаковой длины и не пустые!\n";
            return;
        }
        n = static_cast<int>(input1.size());
    }
    std::list<int> L1(input1.begin(), input1.end());//a1..an
    std::list<int> L2(input2.begin(), input2.end());//b1.....bn
    std::cout << "\n\tИсходный L1 (A): ";
    print_list(L1);
    std::cout << "\n\tИсходный L2 (B): ";
    print_list(L2);
    std::cout << "\n";
    auto i1 = L1.begin();//итер на начало списков
    auto i2 = L2.begin();
    for (int k = 0; k < n; ++k) {
        L2.splice(++i2, L1, i1++);//перемещаем i1++ перед ++i2 вставка
    }
    std::cout << "\n\tРезультатик:\n\t";
    print_list(L2);
    std::cout << "\n\n";
}