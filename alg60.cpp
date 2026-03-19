#include "alg60.h"
#include "utils.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <numeric>
#include <functional>
void task4() {//задание 60
    std::cout << "\n\t~~ Задание 60 (STL3Alg60) ~~\n";
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> input;
    if (method == 1 || method == 2) {
        int n = get_min2();//n>=2
        fill_vector(input, method, n);
    }
    else if (method == 3) {
        read_file_vec(input);
        if (input.size() < 2) {
            std::cout << "\n\tОшибочка( список должен содержать хотя бы 2 элемента!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
    }
    std::list<int> L(input.begin(), input.end());//список чез итер-ы
    std::cout << "\n\tИсходный список L:\n\t";
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    if (L.size() == 1) {
        std::cout << "\n\tСписок из одного элемента — вектор пуст.\n\n";
        return;
    }
    std::cout << "\n\tПары соседей и их средние:\n\t";//вывод пар и их ср
    auto it1 = L.begin();//на перв
    auto it2 = std::next(it1);//на втор
    while (it2 != L.end()) {
        double avg = (static_cast<double>(*it1) + *it2) / 2.0;//среднее
        std::cout << "\n\t(" << *it1 << ", " << *it2 << ") = " << avg;
        ++it1;
        ++it2;
    }
    std::cout << "\n";
    std::vector<double> V;//вектор для ср
    V.reserve(L.size());//память зарезервировали
    std::adjacent_difference(L.begin(), L.end(), std::back_inserter(V), AvgFunctor());
    V.erase(V.begin());//удаляем 1
    std::cout << "\n\tИтоговый вектор V:\n\t";
    for (auto it = V.begin(); it != V.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    std::cin.get();
    std::cin.get();,
}