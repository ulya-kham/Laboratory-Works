#include "bin_converter.h"
#include <fstream>
#include <iostream>
#include <vector>
std::string convert_text_to_binary(const std::string& txt_fname) {//открываем тект фал
    std::ifstream txt_f(txt_fname);
    if (!txt_f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть текстовый файлик \"" << txt_fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return "";
    }
    std::vector<int> nums;//чтениние, проверка и запись 
    int num;
    while (txt_f >> num) {
        if (num < 0) {
            std::cout << "\n\tОшибочка( в файлике есть отрицательное число " << num << "\n";
            std::cout << "\tА по условию должны быть только неотрицательные!\n";
            txt_f.close();
            return "";
        }
        nums.push_back(num);//новый эелемент в окнец
    }
    txt_f.close();
    if (nums.empty()) {
        std::cout << "\n\tОшибочка( файлик пустой! Нет ни одного числа\n";
        return "";
    }
    std::string bin_fname = txt_fname + ".bin";//тмя двоичого файла
    std::ofstream bin_f(bin_fname, std::ios::binary);  // создаём двоичный файлик + открываем в бинарном режжиме
    if (!bin_f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось создать двоичный файлик \"" << bin_fname << "\"\n";
        return "";
    }
    for (int n : nums) {//записываем в двоичном формате
        bin_f.write(reinterpret_cast<const char*>(&n), sizeof(n));
    }
    bin_f.close();
    std::cout << "\n\tУра! Создан двоичный файлик \"" << bin_fname << "\" с " << nums.size() << " числами\n";
    return bin_fname;
}