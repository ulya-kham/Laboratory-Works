#include "file6.h"
#include <fstream>
#include <iostream>
int get_k_el(const std::string& fname, int k) {
    if (k < 1) {
        return -1;
    }
    std::ifstream f(fname, std::ios::binary);//открываем двоичный файцл
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть двоичный файлик \"" << fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return -1;
    }
    f.seekg(0, std::ios::end);   // проверяем размер файлика (конец=размер)
    std::streampos size = f.tellg();
    int count = static_cast<int>(size / sizeof(int));//вычисляем кол-во
    if (k > count) {
        f.close();
        return -1;  
    }
    f.seekg((k - 1) * sizeof(int), std::ios::beg);//прыгаем со смещением с начала
    int result;
    f.read(reinterpret_cast<char*>(&result), sizeof(int));
    f.close();
    return result;
}