#include "alg16.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
void task2() {//задание 16
    std::cout << "\n\t~~ Задание 2 (STL3Alg16) ~~\n";
    std::cout << "\tКак заполнить данные?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    int A, B;
    if (method == 1 || method == 2) {
        A = get_int("\n\tВведи число A: ");
        B = get_int("\tВведи число B: ");
    }
    std::vector<int> V1_vec, V2_vec;
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_min10();//n>=10
        std::cout << "\n\t~ Заполняем векторы чиселками ~\n";
        fill_vector(V1_vec, method, n);
        fill_vector(V2_vec, method, n);
    }
    else if (method == 3) {
        std::cout << "\n\t~ Заполняем вектор V1 ~";
        read_file_vec(V1_vec);
        std::cout << "\n\t~ Заполняем вектор V2 ~";
        read_file_vec(V2_vec);
        if (V1_vec.size() < 10 || V2_vec.size() < 10) {
            std::cout << "\n\tОшибочка( оба вектора должны содержать не менее 10 элементов!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
        A = get_int("\n\tВведи число A: ");
        B = get_int("\tВведи число B: ");
    }
    std::vector<int> V1(V1_vec.begin(), V1_vec.end());
    std::vector<int> V2(V2_vec.begin(), V2_vec.end());
    std::cout << "\n\tИсходный V1:\n\t";
    for (auto it = V1.begin(); it != V1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\tИсходный V2:\n\t";
    for (auto it = V2.begin(); it != V2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::fill(V1.begin(), V1.begin() + 5, A);//первые 5 А (диапазон)
    std::fill(V1.end() - 5, V1.end(), B);//последние 5 В для 1
    std::fill_n(V2.begin(), 5, A);//первые 5 А (количесвто)
    std::fill_n(V2.end() - 5, 5, B);//последние 5 В для 2
    std::cout << "\n\tV1 результатик (первые 5 = A, последние 5 = B):\n\t";
    for (auto it = V1.begin(); it != V1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\tV2 результатик (первые 5 = A, последние 5 = B):\n\t";
    for (auto it = V2.begin(); it != V2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
}