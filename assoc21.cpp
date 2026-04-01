#include "assoc21.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <map>
void task3() {//задание3
    std::cout << "\n\t~~ Задание 3 (STL5Assoc21) ~~\n";
    std::cout << "\tКак заполнить данные?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> V;//создаем вект
    if (method == 1 || method == 2) {
        int n = get_pos();
        std::cout << "\n\t~ Заполняем вектор V ~\n";
        fill_vector(V, method, n);
    }
    else if (method == 3) {
        std::cout << "\n\t~ Заполняем вектор V ~";
        read_file_vec(V);
        if (V.empty()) {
            std::cout << "\n\tОшибочка( вектор V пуст!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
    }
    std::cout << "\n\tИсходный вектор V:\n\t";
    for (auto it = V.begin(); it != V.end(); ++it) {//вывод исходника
        std::cout << *it << " ";
    }
    std::multimap<int, int> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        int last_digit = (*it) % 10;//групируем по последней
        if (*it < 0) last_digit = (-*it) % 10;//отрицательные
        M.insert(std::make_pair(last_digit, *it));//создаем пару и вставляем
    }
    std::cout << "\n\n\tM (ключ - значение):\n\t";
    for (auto it = M.begin(); it != M.end(); ++it) {//вывод по возрастанию
        std::cout << it->first << " " << it->second << "  | ";
    }
    std::cout << "\n";
    std::cin.get();
    std::cin.get();
}