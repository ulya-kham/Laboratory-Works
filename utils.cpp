#include "utils.h"
#include <iostream>
#include <fstream>
#include <random>
#include <limits>
int get_int(const std::string& prompt) {//ввод целого числа с защитой от дуркак
    int value;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int get_n3() {//проверка числа на делимсоть на 3
    int n;
    while (true) {
        n = get_int("\tСколько чисел? (должно делиться на 3): ");
        if (n > 0 && n % 3 == 0) return n;
        std::cout << "\n\tОшибочка( количество должно быть > 0 и делиться на 3!\n";
    }
}
int get_chetn() {//проверка на четностьь
    int n;
    while (true) {
        n = get_int("\tСколько чисел? (должно быть чётное): ");
        if (n > 0 && n % 2 == 0) return n;
        std::cout << "\n\tОшибочка( количество должно быть > 0 и чётным!\n";
    }
}
void fill_vector(std::vector<int>& vec, int method, int n) {//заполнение вектора
    if (method == 1) {//клава
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            vec.push_back(get_int("\t  [" + std::to_string(i + 1) + "]: "));
        }
    }
    else if (method == 2) {//рандомно
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            vec.push_back(x);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
        }
    }
    else if (method == 3) {//файлик
        std::string filename;
        std::ifstream file;
        do {
            std::cout << "\n\tВведи название файла: ";
            std::cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                std::cout << "\n\tОшибочка( файл \"" << filename << "\" не найден!\n";
            }
        } while (!file.is_open());
        int x;
        std::cout << "\n\tЧитаем из файла \"" << filename << "\":\n";
        while (file >> x) {
            vec.push_back(x);
            std::cout << "\t  [" << vec.size() << "]: " << x << "\n";
        }
        file.close();
    }
}
int get_pos() {//проверка на положительное
    int n;
    while (true) {
        n = get_int("\tСколько элементов? (должно быть > 0): ");
        if (n > 0) return n;
        std::cout << "\n\tОшибочка( количество должно быть > 0!\n";
    }
}
void read_file_vec(const std::string& filename, std::vector<int>& vec) {//чтение файла и заполняем в вектор
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "\n\tОшибочка( файл \"" << filename << "\" не найден!\n";
        return;
    }
    int x;
    std::cout << "\n\tЧитаем из файла \"" << filename << "\":\n";
    while (file >> x) {
        vec.push_back(x);
        std::cout << "\t  [" << vec.size() << "]: " << x << "\n";
    }
    file.close();
}