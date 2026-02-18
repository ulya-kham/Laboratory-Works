#include "recur14.h"
#include <iostream>
#include <cctype>
int evaluate_recursive(const std::string& s, size_t pos) {//обрабатывает строку справа налев
    if (pos == 0) {//если дошли до начала, возвращаем первую цифру
        return s[0] - '0';
    }
    if (s[pos] == '+' || s[pos] == '-') {
        int left_value = evaluate_recursive(s, pos - 1);// левая часть всё до оператора
        int right_digit = s[pos + 1] - '0';// правая часть одна цифра после оператора
        if (s[pos] == '+') {
            return left_value + right_digit;
        }
        else {
            return left_value - right_digit;
        }
    }
    return evaluate_recursive(s, pos - 1);// пропускаем цифру и идём дальше влево
}
int calculations(const std::string& expr) {
    if (expr.empty()) {
        std::cout << "\n\tОшибочка( строка пустая!\n";
        return 0;
    }
    if (expr.length() % 2 == 0) {//проверка длины
        std::cout << "\n\tОшибочка( некорректный формат: цыфры, а не числа!\n";
        return 0;
    }

    if (!std::isdigit(static_cast<unsigned char>(expr[0])) ||!std::isdigit(static_cast<unsigned char>(expr.back()))) {//проверка на цифры
        std::cout << "\n\tОшибочка( строка должна начинаться и заканчиваться цифрой\n";
        return 0;
    }
    for (size_t i = 0; i < expr.length(); i++) {//проекра на чередование
        if (i % 2 == 0) {//чет - цифры
            if (!std::isdigit(static_cast<unsigned char>(expr[i]))) {
                std::cout << "\n\tОшибочка( на позиции " << (i + 1) << " должна быть цифра\n";
                return 0;
            }
        }
        else {//иначе опареторы
            if (expr[i] != '+' && expr[i] != '-') {
                std::cout << "\n\tОшибочка( на позиции " << (i + 1) << " должен быть оператор (+ или -)\n";
                return 0;
            }
        }
    }
    return evaluate_recursive(expr, expr.length() - 2); // запускаем рекурсию с предпоследнего символа
}