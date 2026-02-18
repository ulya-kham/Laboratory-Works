#include "file48.h"
#include <fstream>
#include <iostream>
int interleave(const std::string& sa, const std::string& sb, const std::string& sc, const std::string& sd) {
    std::ifstream f_a(sa, std::ios::binary);// открываем три входных файлика для чтения
    std::ifstream f_b(sb, std::ios::binary);
    std::ifstream f_c(sc, std::ios::binary);
    if (!f_a.is_open() || !f_b.is_open() || !f_c.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть один из входных файликов:\n";
        if (!f_a.is_open()) std::cout << "\t  " << sa << "\n";
        if (!f_b.is_open()) std::cout << "\t  " << sb << "\n";
        if (!f_c.is_open()) std::cout << "\t  " << sc << "\n";
        return -1;
    }
    f_a.seekg(0, std::ios::end); // проверяем размеры файликов
    f_b.seekg(0, std::ios::end);
    f_c.seekg(0, std::ios::end);
    std::streampos size_a = f_a.tellg();//в байтах размеры
    std::streampos size_b = f_b.tellg();
    std::streampos size_c = f_c.tellg();
    if (size_a != size_b || size_b != size_c) {
        std::cout << "\n\tОшибочка( файлики имеют разный размер!\n";
        std::cout << "\t  " << sa << ": " << (size_a / sizeof(int)) << " элементов\n";
        std::cout << "\t  " << sb << ": " << (size_b / sizeof(int)) << " элементов\n";
        std::cout << "\t  " << sc << ": " << (size_c / sizeof(int)) << " элементов\n";
        f_a.close();
        f_b.close();
        f_c.close();
        return -1;
    }
    int count = static_cast<int>(size_a / sizeof(int));
    std::cout << "\n\tВсе файлики содержат по " << count << " элементов\n";
    f_a.seekg(0, std::ios::beg);//возвращаемся в начало файликов
    f_b.seekg(0, std::ios::beg);
    f_c.seekg(0, std::ios::beg);
    std::ofstream f_d(sd, std::ios::binary | std::ios::trunc);// открываем выходной файлик для записи
    if (!f_d.is_open()) {
        std::cout << "\n\tОшибочка( не удалось создать выходной файлик \"" << sd << "\"\n";
        f_a.close();
        f_b.close();
        f_c.close();
        return -1;
    }
    int a, b, c;
    int total_written = 0;
    std::cout << "\n\tЧередуем элементы:\n";// читаем и записываем
    for (int i = 0; i < count; i++) {
        f_a.read(reinterpret_cast<char*>(&a), sizeof(a));
        f_b.read(reinterpret_cast<char*>(&b), sizeof(b));
        f_c.read(reinterpret_cast<char*>(&c), sizeof(c));
        f_d.write(reinterpret_cast<const char*>(&a), sizeof(a));
        f_d.write(reinterpret_cast<const char*>(&b), sizeof(b));
        f_d.write(reinterpret_cast<const char*>(&c), sizeof(c));
        total_written += 3;
    }
    f_a.close();
    f_b.close();
    f_c.close();
    f_d.close();
    std::cout << "\tУра! Создан файлик \"" << sd << "\" с " << total_written << " элементами (чередование: A, B, C)\n";
    return total_written;
}