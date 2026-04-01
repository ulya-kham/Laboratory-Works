#include "assoc2.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
void task1() {//задание1
    std::cout << "\n\t~~ Задание 1 (STL5Assoc2) ~~\n";
    std::cout << "\n\tКак будете заполнять данные?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> V0_vec;//вводим вект v0
    if (method == 1 || method == 2) {
        std::cout << "\n\t~ Заполняем вектор V0 ~\n";
        int n0 = get_pos();
        fill_vector(V0_vec, method, n0);
    }
    else if (method == 3) {
        std::cout << "\n\t~ Заполняем вектор V0 ~";
        read_file_vec(V0_vec);//считываем из файла
        if (V0_vec.empty()) {
            std::cout << "\n\tОшибочка( V0 не должен быть пуст!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
    }
    std::cout << "\n\tКоличество векторов:\n";
    int N = get_pos();//>0
    std::vector<std::vector<int>> vectors(N);//вводим н-кол-во векторов
    for (int i = 0; i < N; ++i) {
        std::cout << "\n\t~ Заполняем вектор V" << (i + 1) << " ~\n";//заполняем каждый вектор
        if (method == 1 || method == 2) {
            int n_i = get_pos();
            while (n_i < static_cast<int>(V0_vec.size())) {
                std::cout << "\n\tОшибочка( размер V" << (i + 1) << " должен быть >= " << V0_vec.size() << "!\n";//новые не меньше v0
                n_i = get_pos();
            }
            fill_vector(vectors[i], method, n_i);
        }
        else if (method == 3) {
            read_file_vec(vectors[i]);
            if (vectors[i].size() < V0_vec.size()) {
                std::cout << "\n\tОшибочка( размер V" << (i + 1) << " должен быть >= " << V0_vec.size() << "!\n";
                std::cout << "\n\tНажми что нибудь для возврата в меню...";
                std::cin.get();
                std::cin.get();
                return;
            }
        }
    }
    std::set<int> S0(V0_vec.begin(), V0_vec.end());//преобразуем в множество
    std::cout << "\n\tМножество S0 (из V0):\n\t";
    for (auto it = S0.begin(); it != S0.end(); ++it) {
        std::cout << *it << " ";
    }
    std::vector<int> count_vect;//находим подходящих
    for (int i = 0; i < N; ++i) {
        std::set<int> Si(vectors[i].begin(), vectors[i].end());
        if (std::includes(Si.begin(), Si.end(), S0.begin(), S0.end())) {
            count_vect.push_back(i + 1);//сохраняем номер вектора
        }
    }
    std::cout << "\n\n\tКоличество векторов, содержащих все элементы V0: " << count_vect.size() << "\n";
    if (!count_vect.empty()) {
        std::cout << "\n\tПодходящие векторы: ";
        for (size_t j = 0; j < count_vect.size(); ++j) {
            if (j > 0) std::cout << ", ";
            std::cout << "V" << count_vect[j];
        }
        std::cout << "\n";
    }
    std::cin.get();
    std::cin.get();
}