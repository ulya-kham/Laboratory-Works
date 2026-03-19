#include "alg6.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
void task1() {//задание 6
    std::cout << "\n\t~~ Задание 1 (STL3Alg6) ~~\n";
    std::cout << "\tКак заполнить данные?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<int> V_vec, L_vec;
    int nV = 0;
    if (method == 1 || method == 2) {
        nV = get_chetn(); //полож и четное
        std::cout << "\n\t~ Заполняем вектор V ~\n";
        fill_vector(V_vec, method, nV);
        std::cout << "\n\t~ Заполняем список L ~\n";
        int nL = get_pos(); //полож
        fill_vector(L_vec, method, nL);
    }
    else if (method == 3) {
        std::cout << "\n\t~ Заполняем вектор V ~";
        read_file_vec(V_vec); 
        std::cout << "\n\t~ Заполняем список L ~";
        read_file_vec(L_vec); 
        if (V_vec.empty() || V_vec.size() % 2 != 0) {
            std::cout << "\n\tОшибочка( вектор V должен быть не пуст и иметь чётное кол-во элементов!\n";
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            return;
        }
    }
    std::vector<int> V_half(V_vec.begin(), V_vec.begin() + V_vec.size() / 2);//первая половина вектора
    std::list<int> L(L_vec.begin(), L_vec.end());//список чрз итер-ы
    std::cout << "\n\tИсходный вектор V:\n\t";
    int mid = V_vec.size() / 2;
    for (int i = 0; i < V_vec.size(); ++i) {
        std::cout << V_vec[i] << " ";
        if (i == mid - 1) std::cout << "| ";//разделитель
    }
    std::cout << "\n\tИсходный список L:\n\t";
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    auto last_found = L.end();//последний, который подхоит
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (std::find_first_of(it, std::next(it), V_half.begin(), V_half.end()) != std::next(it)) {//поиск по вектору текущий эл
            last_found = it; //обновляем
        }
    }
    if (last_found != L.end()) {
        L.insert(std::next(last_found), *last_found);//дублируем после
        std::cout << "\n\tНайден элементик " << *last_found << " - продублирован.\n";
    }
    else {
        std::cout << "\n\tСовпадений не найдено :( списочек не изменён.\n";
    }
    std::cout << "\n\tИтоговый списочек L:\n\t";
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    std::cin.get();
    std::cin.get();
}