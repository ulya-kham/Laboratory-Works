#include "homedyn13.h"
#include <iostream>
#include <fstream>
#include <cmath>

bool read_params(const std::string& fname, int& k, int& n) {//читаем файлиек
    std::ifstream f(fname);
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть файлик \"" << fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return false;
    }
    if (!(f >> k >> n)) {
        std::cout << "\n\tОшибочка( в файлике должны быть два числа: K и N\n";
        f.close();
        return false;
    }
    if (k < 2 || k > 10) {
        std::cout << "\n\tОшибочка( основание системы счисления K должно быть от 2 до 10 (а у тебя K=" << k << ")\n";
        f.close();
        return false;
    }
    if (n <= 1 || n >= 20) {
        std::cout << "\n\tОшибочка( количество разрядов N должно быть от 2 до 19 (а у тебя N=" << n << ")\n";
        f.close();
        return false;
    }
    if (k + n >= 26) {
        std::cout << "\n\tОшибочка( сумма K+N должна быть меньше 26 (а у тебя K+N=" << (k + n) << ")\n";
        f.close();
        return false;
    }
    f.close();
    return true;
}
double count_valid_numbers(int k, int n) {//подсчет без 2-0
    double prev_nonzero = k - 1;//не 0 в начале
    double prev_zero = 0.0;
    for (int i = 2; i <= n; i++) {//строим от 2 до н разряда
        double curr_nonzero = (prev_nonzero + prev_zero) * (k - 1);//добавлеяем не ноль
        double curr_zero = prev_nonzero;//+0 если не ноль
        prev_nonzero = curr_nonzero;//сдвигаем
        prev_zero = curr_zero;
    }
    return prev_nonzero + prev_zero;//числа длины н и на 0 и нет
}
bool write_result(const std::string& fname, double result) {
    std::ofstream f(fname);
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось создать выходной файлик \"" << fname << "\"\n";
        return false;
    }
    f << result;
    f.close();
    std::cout << "\n\tУра! Результат записан в файлик \"" << fname << "\"\n";
    return true;
}