#include "file29.h"
#include <fstream>
#include <iostream>
int truncate(const std::string& fname) {
    std::ifstream f_in(fname, std::ios::binary);// открываем файлик для чтения
    if (!f_in.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть двоичный файлик \"" << fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return -1;
    }
    f_in.seekg(0, std::ios::end);// проверяем размер файлика
    std::streampos size = f_in.tellg();
    int count = static_cast<int>(size / sizeof(int));
    if (count <= 50) {
        std::cout << "\n\tОшибочка( в файлике всего " << count << " элементов\n";
        std::cout << "\tА нужно больше 50, чтобы уменьшить до 50!\n";
        f_in.close();
        return -1;
    }
    int removed = count - 50;// считаем, сколько элементов удалим
    std::cout << "\n\tВ файлике " << count << " элементов, удаляем " << removed << " последних...\n";
    f_in.seekg(0, std::ios::beg);// читаем первые 50 эл
    int buffer[50];
    f_in.read(reinterpret_cast<char*>(buffer), 50 * sizeof(int));//читаем с преобразованием в чар
    f_in.close();
    std::ofstream f_out(fname, std::ios::binary | std::ios::trunc);// все удаляется так как флаг 
    if (!f_out.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть файлик для записи \"" << fname << "\"\n";
        return -1;
    }
    f_out.write(reinterpret_cast<const char*>(buffer), 50 * sizeof(int));// записываем только первые 50 элементов
    f_out.close();
    std::cout << "\tУра! Файлик уменьшен до 50 элементов\n";
    return removed;
}