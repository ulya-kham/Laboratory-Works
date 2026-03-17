#include "iter8.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <random>
std::string generate_random_word(int len) {//генерация случ слова
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25);
    std::string word;
    for (int i = 0; i < len; ++i) {
        word += alpha[dis(gen)];
    }
    return word;
}
void create_file(const std::string& filename) {//создание файла 3 способами
    std::cout << "\n\tКак создать входной файл \"" << filename << "\"?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Использовать существующий\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    if (method == 1) {//клавитарура 
        std::cout << "\n\tВведи слова (через пробел или Enter, заверши точкой):\n\t";
        std::ofstream file(filename);
        std::string word;
        while (std::cin >> word && word != ".") {
            file << word << " ";
        }
        file.close();
        std::cout << "\n\tФайл \"" << filename << "\" создан.\n";
    }
    else if (method == 2) {//случайно
        int n = get_pos();
        std::ofstream file(filename);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> len_dis(1, 10);
        for (int i = 0; i < n; ++i) {
            int len = len_dis(gen);
            file << generate_random_word(len) << " ";
        }
        file.close();
        std::cout << "\n\tФайл \"" << filename << "\" заполнен " << n << " случайными словами.\n";
    }
    else if (method == 3) {//файлик
        std::cout << "\n\tУбедись, что файл \"" << filename << "\" существует в папке проекта.\n";
    }
}
void task4() {//задание4
    std::cout << "\n\t~~ Задание 4 (STL1Iter8) ~~\n\n";
    int K = get_int("\tВведи K (> 0): ");
    while (K <= 0) {
        std::cout << "\n\tОшибочка( K должно быть >0!\n";
        K = get_int("\tДавай по новой: ");
    }
    std::string name1 = "input_words.txt";
    std::string name2 = "output_filtered.txt";
    create_file(name1);
    std::ifstream in_check(name1);//проверка существования
    if (!in_check.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть входной файл \"" << name1 << "\"!\n";
        return;
    }
    std::cout << "\n\tИсходные слова из файла \"" << name1 << "\":\n\t";
    std::string word;
    while (in_check >> word) {
        std::cout << word << " ";
    }
    in_check.close();
    std::cout << "\n";
    std::ifstream in_file(name1);//открываем для чтения и записи
    std::ofstream out_file(name2);
    std::istream_iterator<std::string> in_begin(in_file), in_end;//создание итераторов
    std::ostream_iterator<std::string> out_iter(out_file, "\n");
    std::remove_copy_if(in_begin, in_end, out_iter, [K](const std::string& w) { return w.length() > K; });//копируем
    in_file.close();
    out_file.close();
    std::cout << "\n\tОтфильтрованные слова (длина <= " << K << "):\n\t";
    std::ifstream out_check(name2);
    while (out_check >> word) {
        std::cout << word << " ";
    }
    out_check.close();
    std::cout << "\n";
    std::cout << "\n\tРезультат также записан в файл \"" << name2 << "\" (по одному слову на строке)\n\n";
}