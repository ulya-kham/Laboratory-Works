#include "alg36.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
void task3() {//задание 3
    std::cout << "\n\t~~ Задание 3 (STL3Alg36) ~~\n";
    std::cout << "\tКак заполнить вектор?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> V;
    if (method == 1 || method == 2) {
        int n = get_nechet_min3(); //нечет>=3
        fill_vector(V, method, n);
    }
    else if (method == 3) {
        read_file_vec(V);
        if (V.size() < 3 || V.size() % 2 == 0) {
            std::cout << "\n\tОшибочка( вектор должен содержать нечётное кол-во элементов >=3!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
    }
    std::cout << "\n\tИсходный вектор:\n\t";
    for (auto it = V.begin(); it != V.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    size_t mid = V.size() / 2;//центр
    std::nth_element(V.begin(), V.begin() + mid, V.end());//центр на место мид
    int center = V[mid];
    auto left_max = std::max_element(V.begin(), V.begin() + mid);//макс слева
    auto right_min = std::min_element(V.begin() + mid + 1, V.end());//мин справа
    std::cout << "\n\tТри средних элемента после сортировочки:\n\t";
    std::cout << *left_max << " " << center << " " << *right_min << "\n";
    std::vector<int> V_sorted(V.begin(), V.end());
    std::sort(V_sorted.begin(), V_sorted.end());
    std::cout << "\n\tПолностью отсортированный вектор:\n\t";
    for (auto it = V_sorted.begin(); it != V_sorted.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    std::cin.get();
    std::cin.get();
}