#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <vector>
#include "backrec4.h"
#include "homedyn1.h"
#include "homedyn13.h"
void t1();
void t2();
void t3();
int main() {
    std::setlocale(LC_ALL, "Russian");
    int vibor;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа №8 ~~\n\n";
        std::cout << "\t1. Задание 1 - Экспидиция (BackRec4)\n";
        std::cout << "\t2. Задание 2 - Черепашка - Тортилла (HomeDyn1)\n";
        std::cout << "\t3. Задание 3 - К-ичные числа (HomeDyn13)\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        std::cout << "\n\tВыберите задачу: ";
        while (!(std::cin >> vibor)) {//защита от букв
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tНу нет, цифры от 0 до 3... А ты другое ввёл, давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//чистим буфер
        while (vibor < 0 || vibor > 3) {//тоже защита от дурака
            std::cout << "\n\tНу нет, цифры от 0 до 3... А ты другое ввёл, давай по новой: ";
            while (!(std::cin >> vibor)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tНу нет, цифры от 0 до 3... А ты другое ввёл, давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("cls");
        switch (vibor) {
        case 1:
            t1();
            break;
        case 2:
            t2();
            break;
        case 3:
            t3();
            break;
        case 0:
            std::cout << "\n\tМожешь не возвращаться) Пока-пока))\n\n";
            break;
        }
        if (vibor != 0) {
            std::cout << "\n\tНажми что-нибудь для продолжения... Иначе мир взорвется ";
            std::cin.get();
            system("cls");
        }
    } while (vibor != 0);
    return 0;
}

void t1() {
    std::cout << "\n\t\t~~ Задание 1 (BACKREC4) ~~\n\n";
    std::cout << "\tВведите имя файлика: ";
    std::string fname;
    std::getline(std::cin, fname);
    if (fname.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::vector<Art> arts;
    int min_w, max_w;
    if (!read_data(fname, arts, min_w, max_w)) {
        return;
    }
    std::vector<bool> best;//какие артефакты берем
    int best_vol;//миним. объем
    find_optimal(arts, min_w, max_w, best, best_vol);
    print_result(arts, best, best_vol, min_w, max_w);
}

void t2() {
    std::cout << "\n\t\t~~ Задание 2 (HOMEDYN1) ~~\n\n";
    std::cout << "\tИмя входного файлика: ";
    std::string in_fname;
    std::getline(std::cin, in_fname);
    if (in_fname.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::cout << "\tИмя выходного файлика: ";
    std::string out_fname;
    std::getline(std::cin, out_fname);
    if (out_fname.empty()) {
        std::cout << "\n\tНазвание выходного файлика тоже пустое :( плак - плак вдвойне\n";
        return;
    }
    std::vector<std::vector<int>> board;//доска n*n
    int n;
    if (!read_board(in_fname, board, n)) {
        return;
    }
    int max_sum = find_max_sum(board, n);//ищем макс. сумму
    std::cout << "\n\t~~ Результатик: ~~\n\n";
    std::cout << "\tМаксимальная сумма на пути черепашки: " << max_sum << "\n";
    write_result(out_fname, max_sum);//записываем в другой файл
}

void t3() {
    std::cout << "\n\t\t~~ Задание 3 (HOMEDYN13) ~~\n\n";
    std::cout << "\tИмя входного файлика: ";
    std::string in_fname;
    std::getline(std::cin, in_fname);
    if (in_fname.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::cout << "\tИмя выходного файлика: ";
    std::string out_fname;
    std::getline(std::cin, out_fname);
    if (out_fname.empty()) {
        std::cout << "\n\tНазвание выходного файлика тоже пустое :( плак - плак вдвойне\n";
        return;
    }
    int k, n;
    if (!read_params(in_fname, k, n)) {
        return;
    }
    std::cout << "\n\tСчитаем К-ичные чиселки без двух нулей подряд...\n";
    double count = count_valid_numbers(k, n);//подсчет
    std::cout << "\n\t~~ Результатик: ~~\n\n";
    std::cout << "\tКоличество " << k << "-ичных чисел из " << n << " разрядов без двух нулей подряд: " << count << "\n";
    write_result(out_fname, count);//записываем
}