#include "circular_string_list.h"
#include <fstream>
#include <iostream>
CircularStringList::CircularStringList() : head(nullptr) {}
CircularStringList::~CircularStringList() {
    clear();
}
void CircularStringList::clear() {
    if (!head) return;
    CStringNode* current = head;
    do {
        CStringNode* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
    head = nullptr;
}
void CircularStringList::push_back(const std::string& name) {
    CStringNode* new_node = new CStringNode(name);
    if (!head) {
        head = new_node;
        head->next = head;
    }
    else {
        CStringNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = new_node;
        new_node->next = head;
    }
}
void CircularStringList::josephus(int k, const std::string& output_filename) {
    if (!head) return;
    std::ofstream file(output_filename);
    if (!file.is_open()) {
        std::cout << "\n\tОшибка! Не удалось открыть файл \"" << output_filename << "\"\n";
        return;
    }
    std::cout << "\n\t~~ Считалка (k=" << k << ") ~~\n";
    CStringNode* current = head;
    int step = 1;
    while (head) {
        for (int i = 0; i < k - 1; ++i) {//передвигаемся 
            current = current->next;
        }
        std::string eliminated = current->name;
        file << eliminated << "\n";
        std::cout << "\nШаг " << step << ": Уничтожается: " << eliminated;
        if (head == current && head->next == head) {
            delete current; //последний элемент
            head = nullptr;
            current = nullptr;
            std::cout << "\n  Осталось: пусто";
        }
        else {
            CStringNode* prev = head; //находим предшественника
            while (prev->next != current) {
                prev = prev->next;
            }
            if (current == head) {
                head = current->next;
            }
            prev->next = current->next;
            CStringNode* next_node = current->next;
            delete current;
            current = next_node;
            std::cout << "\n  Выжившие: ";
            CStringNode* p = current;
            do {
                std::cout << p->name;
                p = p->next;
                if (p != current) std::cout << " - ";
            } while (p != current);
        }
        step++;

    }
    file.close();
    std::cout << "\n\n\tРезультат записан в \"" << output_filename << "\"\n";
}