#include "seq5.h"
#include "utils.h"
#include <iostream>
#include <list>
void print_forward(const std::list<int>& L) {//вывод чрз прямые итераторы
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
}
void print_reverse(const std::list<int>& L) {//вывод чрз обратные итераторы
    for (auto rit = L.rbegin(); rit != L.rend(); ++rit) {
        std::cout << *rit << " ";
    }
}
void task1() {//задание 1
    std::cout << "\n\t~~ Задание 1 (STL2Seq5) ~~\n\n";
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> input;//вектор
    if (method == 1 || method == 2) {
        int n = get_n3();// n делится на 3
        fill_vector(input, method, n);//заполняем из файлика
    }
    else if (method == 3) {
        fill_vector(input, method, 0);
        if (input.empty() || input.size() % 3 != 0) {
            std::cout << "\n\tОшибочка( количество чисел в файле должно быть > 0 и делиться на 3!\n";
            return;
        }
    }
    int n = static_cast<int>(input.size());
    std::list<int> L(input.begin(), input.end());//создаем список черерз итераторы
    std::cout << "\n\tИсходный список:\n\t";
    print_forward(L);
    std::cout << "\n";
    int part = n / 3;
    std::list<int> result;//итоговый список
    auto it = L.begin();
    for (int i = 0; i < part; ++i, ++it) {
        result.push_back(*it);//1.прямой порядок
    }
    auto rit2 = L.rbegin();
    std::advance(rit2, part);
    for (int i = 0; i < part; ++i, ++rit2) {
        result.push_back(*rit2);//2.обратный
    }
    auto rit3 = L.rbegin();
    for (int i = 0; i < part; ++i, ++rit3) {
        result.push_back(*rit3);//3.обратный
    }
    std::cout << "\n\tПервая треть (прямой порядок):\n\t";
    it = L.begin();
    for (int i = 0; i < part; ++i, ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n\tВторая треть (обратный порядок):\n\t";
    rit2 = L.rbegin();
    std::advance(rit2, part);
    for (int i = 0; i < part; ++i, ++rit2) {
        std::cout << *rit2 << " ";
    }
    std::cout << "\n\n\tТретья треть (обратный порядок):\n\t";
    rit3 = L.rbegin();
    for (int i = 0; i < part; ++i, ++rit3) {
        std::cout << *rit3 << " ";
    }
    std::cout << "\n\n\tИтоговый список:\n\t";
    print_forward(result);
    std::cout << "\n\n";
}