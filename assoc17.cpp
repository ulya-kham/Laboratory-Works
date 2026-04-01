#include "assoc17.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <random>
void task2() {//задание2
    std::cout << "\n\t~~ Задание 2 (STL5Assoc17) ~~\n";
    std::cout << "\tКак заполнить данные?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int("\n\tВыбери: ");
    while (method < 1 || method > 3) {
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
        method = get_int();
    }
    std::vector<std::string> V;//вектор
    if (method == 1 || method == 2) {
        int n = get_pos();
        std::cout << "\n\t~ Заполняем вектор V ~\n";
        if (method == 1) {
            std::cout << "\n\tВведи " << n << " английских слов (ТОЛЬКО ЗАГЛАВНЫЕ БУКВЫ):\n";
            for (int i = 0; i < n; ++i) {
                std::string word;
                std::cout << "\t  [" << (i + 1) << "]: ";
                std::cin >> word;
                while (!is_valid_word(word)) {//провекрка на загл англ буквы
                    std::cout << "\n\tОшибочка( слово должно содержать ТОЛЬКО ЗАГЛАВНЫЕ английские буквы!\n";
                    std::cout << "\t  [" << (i + 1) << "]: ";
                    std::cin >> word;
                }
                V.push_back(word);//добавлем слово в вкектор 
            }
        }
        else if (method == 2) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> len_dist(1, 8);//длина 1-8
            std::uniform_int_distribution<> char_dist('A', 'Z');//заглавные
            std::cout << "\n\tГенерим " << n << " случайных слов из заглавных букв:\n";
            for (int i = 0; i < n; ++i) {
                int len = len_dist(gen);
                std::string word;
                for (int j = 0; j < len; ++j) {
                    word += static_cast<char>(char_dist(gen));
                }
                V.push_back(word);
                std::cout << "\t  [" << (i + 1) << "]: " << word << "\n";
            }
        }
    }
    else if (method == 3) {
        std::cout << "\n\t~ Заполняем вектор V ~";
        std::string filename;
        std::ifstream file;
        do {
            std::cout << "\n\tВведи имя файлика: ";
            std::cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                std::cout << "\n\tОшибочка( файлик \"" << filename << "\" не найден! Попробуй ещё.\n";
            }
        } while (!file.is_open());
        std::string word;
        std::cout << "\n\tЧитаем из файлика \"" << filename << "\":\n";
        while (file >> word) {
            if (!is_valid_word(word)) {
                std::cout << "\n\tОшибочка( слово \"" << word << "\" содержит недопустимые символы!\n";
                std::cout << "\n\tНажми что нибудь для возврата в меню...";
                std::cin.get();
                std::cin.get();
                file.close();
                return;
            }
            V.push_back(word);
            std::cout << "\t  [" << V.size() << "]: " << word << "\n";
        }
        file.close();
    }
    if (V.empty()) {
        std::cout << "\n\tОшибочка( вектор V пуст!\n";
        std::cout << "\n\tНажми что нибудь для возврата в меню...";
        std::cin.get();
        std::cin.get();
        return;
    }
    std::cout << "\n\tИсходный вектор V:\n\t";
    for (auto it = V.begin(); it != V.end(); ++it) {//вывод исходника
        std::cout << *it << " ";
    }
    std::map<char, int> M;//отображение
    for (auto it = V.begin(); it != V.end(); ++it) {
        char first_char = (*it)[0];//берем 1 букву
        M[first_char] += static_cast<int>(it->size());//+ знач по ключу
    }
    std::cout << "\n\n\tРезультатик:\n\t";
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << " - " << it->second << " | ";//ключ-знач
    }
    std::cout << "\n";
    std::cin.get();
    std::cin.get();
}