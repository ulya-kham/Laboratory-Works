#include "seq8.h"
#include "utils.h"
#include <iostream>
#include <vector>
void print_vector(const std::vector<int>& v) {//вывод чрз итераторы
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
}
void task2() {//задание2
    std::cout << "\n\t~~ Задание 2 (STL2Seq8) ~~\n\n";
    std::cout << "\tКак заполнить вектор?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_chetn();//получаем чётное n
    }
    std::vector<int> V;//создание
    fill_vector(V, method, n);//заполнение
    if (method == 3) {
        if (V.empty() || V.size() % 2 != 0) {
            std::cout << "\n\tОшибочка( количество чисел в файле должно быть чётным!\n";
            return;
        }
    }
    std::cout << "\n\tИсходный вектор:\n\t";
    print_vector(V);
    std::cout << "\n";
    auto pos = V.begin() + V.size() / 2;//середина вектора
    V.insert(pos, 5, 0);//вставка для 5 0
    std::cout << "\n\tВектор после вставки 5 нулей в середину:\n\t";
    print_vector(V);
    std::cout << "\n\n";
}