#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <fstream>
#include "file6.h"
#include "file29.h"
#include "file48.h" 
#include "recur14.h"
#include "bin_converter.h"
void t1();
void t2();
void t3();
void t4();
int main() {
    std::setlocale(LC_ALL, "Russian");
    int vibor;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа №9 ~~\n\n";
        std::cout << "\t1. Задание 1 - K элемент из бинарного файлика (File6)\n";
        std::cout << "\t2. Задание 2 - Уменьшить файлик до 50 (File29)\n";
        std::cout << "\t3. Задание 3 - Чередование (File48)\n";
        std::cout << "\t4. Задание 4 - Рекурсивный калькулятор на циферки\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        std::cout << "\n\tВыберите задачу: ";
        while (!(std::cin >> vibor)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tНу нет, цифры от 0 до 4... А ты другое ввёл, давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (vibor < 0 || vibor > 4) {
            std::cout << "\n\tНу нет, цифры от 0 до 4... А ты другое ввёл, давай по новой: ";
            while (!(std::cin >> vibor)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tНу нет, цифры от 0 до 4... А ты другое ввёл, давай по новой: ";
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
        case 4:
            t4();
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
    std::cout << "\n\t\t~~ Задание 1 (FILE6) ~~\n\n";
    std::cout << "\tВведите имя текстового файлика: ";
    std::string txt_fname;
    std::getline(std::cin, txt_fname);
    if (txt_fname.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::string bin_fname = convert_text_to_binary(txt_fname);//конвертруем
    if (bin_fname.empty()) {
        return;
    }
    std::cout << "\tВведите номер элемента K: ";
    int k;
    if (!(std::cin >> k)) {
        std::cout << "\n\tОшибочка( K должно быть целым числом\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int result = get_k_el(bin_fname, k);
    std::cout << "\n\t~~ Результатик: ~~\n\n";
    if (result == -1) {
        std::cout << "\tK элемент: -1 (элемент не найден, грустно и точка.(\n";
    }
    else {
        std::cout << "\tK элемент: " << result << "\n";
    }
}
void check_file_size(const std::string& fname) {// проверяет размер файлика и выводит инфу
    std::ifstream f(fname, std::ios::binary);
    f.seekg(0, std::ios::end);//перемещаем указатель в конец
    std::streampos size = f.tellg();//скажет текущий размер
    int count = static_cast<int>(size / sizeof(int));
    std::cout << "\n\tРазмер файла \"" << fname << "\": " << size << " байт \n";
    std::cout << "\tКол-во элементов: " << count << "\n";
}
void t2() {
    std::cout << "\n\t\t~~ Задание 2 (FILE29) ~~\n\n";
    std::cout << "\tВведите имя текстового файлика: ";
    std::string txt_fname;
    std::getline(std::cin, txt_fname);
    if (txt_fname.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::string bin_fname = convert_text_to_binary(txt_fname);
    if (bin_fname.empty()) {
        return;
    }
    check_file_size(bin_fname);//до обрезки
    int removed = truncate(bin_fname);
    if (removed > 0) {
        std::cout << "\n\t~~ Результатик: ~~\n";
        check_file_size(bin_fname);//после обрезки
    }
}
void t3() {
    std::cout << "\n\t\t~~ Задание 3 (FILE48) ~~\n\n";
    std::cout << "\tВведите имя первого текстового файлика: ";
    std::string txt_a;
    std::getline(std::cin, txt_a);
    if (txt_a.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::cout << "\tВведите имя второго текстового файлика: ";
    std::string txt_b;
    std::getline(std::cin, txt_b);
    if (txt_b.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::cout << "\tВведите имя третьего текстового файлика: ";
    std::string txt_c;
    std::getline(std::cin, txt_c);
    if (txt_c.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::cout << "\tВведите имя выходного файлика: ";
    std::string sd;
    std::getline(std::cin, sd);
    if (sd.empty()) {
        std::cout << "\n\tНазвание пустое :( плак - плак\n";
        return;
    }
    std::string bin_a = convert_text_to_binary(txt_a);// конвертируем текстовые файлики в двоичные
    std::string bin_b = convert_text_to_binary(txt_b);
    std::string bin_c = convert_text_to_binary(txt_c);
    if (bin_a.empty() || bin_b.empty() || bin_c.empty()) {
        return;
    }
    int result = interleave(bin_a, bin_b, bin_c, sd);// создаём новый файлик с чередованием
    if (result > 0) {
        std::cout << "\n\t~~ Результатик: ~~\n";
        std::cout << "\n\tСоздан файлик \"" << sd << "\" с " << result << " элементами!\n";
    }
}
void t4() {
    std::cout << "\n\t\t~~ Задание 4 (RECUR14) ~~\n\n";
    std::cout << "\tВведите выражение без пробелов (только цифры, +, -): ";
    std::string expr;
    std::getline(std::cin, expr);
    if (expr.empty()) {
        std::cout << "\n\tСтрока пустая :( плак - плак\n";
        return;
    }
    std::string clean_expr;//новая строка (свобода от проблелов)
    for (char c : expr) {
        if (c != ' ') {
            clean_expr += c;
        }
    }
    int result = calculations(clean_expr);
    std::cout << "\n\t~~ Результатик: ~~\n\n";
    std::cout << "\tВыражение: " << clean_expr << "\n";
    std::cout << "\tРезультат: " << result << "\n";
}