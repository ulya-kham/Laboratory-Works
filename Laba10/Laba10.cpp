#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <fstream>
#include <random>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
int get_int(const std::string& a = "") {
    int value;
    while (true) {
        if (!a.empty()) {
            std::cout << a;
        }
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void menu_task1();
void menu_task2();
void menu_task3();
void menu_task4();
void menu_task5();
void demo_stack_operations();
void demo_queue_operations();
void demo_list_operations();
void t1();
void t2();
void t3();
void t4();
void t5();
int main() {
    std::setlocale(LC_ALL, "Russian");
    int vibor;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа 10 ~~\n\n";
        std::cout << "\t1. Задание 1 - Стек (Dynamic3)\n";
        std::cout << "\t2. Задание 2 - Очередь (Dynamic24)\n";
        std::cout << "\t3. Задание 3 - Список (ListWork1)\n";
        std::cout << "\t4. Задание 4 - Список (ListWork22)\n";
        std::cout << "\t5. Задание 5 - Список (ListWork59)\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        std::cout << "\n\tВыбери задачку: ";

        while (!(std::cin >> vibor)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( цифры от 0 до 5... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (vibor < 0 || vibor > 5) {
            std::cout << "\n\tОшибочка( цифры от 0 до 5... Давай по новой: ";
            while (!(std::cin >> vibor)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( цифры от 0 до 5... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        system("cls");
        switch (vibor) {
        case 1: menu_task1(); break;
        case 2: menu_task2(); break;
        case 3: menu_task3(); break;
        case 4: menu_task4(); break;
        case 5: menu_task5(); break;
        case 0: std::cout << "\n\tМожешь не возвращаться) Пока-пока))\n\n"; break;
        }

        if (vibor != 0) {
            std::cout << "\n\tНажми что нибудь, чтобы вернуться в главное меню...";
            std::cin.get();
            system("cls");
        }
    } while (vibor != 0);
    return 0;
}
void menu_task1() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 1 (DYNAMIC3) ~~\n\n";
        std::cout << "\t1. Операции над стеком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери: ";
        while (!(std::cin >> pod_vibor) || pod_vibor < 0 || pod_vibor > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери 0, 1 или 2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pod_vibor) {
        case 1:
            system("cls");
            demo_stack_operations();
            break;
        case 2:
            system("cls");
            t1();
            break;
        case 0:
            return;
        }

        if (pod_vibor != 0) {
            std::cout << "\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}
void menu_task2() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 2 (DYNAMIC24) ~~\n\n";
        std::cout << "\t1. Операции над очередью\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери: ";
        while (!(std::cin >> pod_vibor) || pod_vibor < 0 || pod_vibor > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери 0, 1 или 2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pod_vibor) {
        case 1:
            system("cls");
            demo_queue_operations();
            break;
        case 2:
            system("cls");
            t2();
            break;
        case 0:
            return;
        }

        if (pod_vibor != 0) {
            std::cout << "\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task3() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 3 (LISTWORK1) ~~\n\n";
        std::cout << "\t1. Операции над списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери: ";
        while (!(std::cin >> pod_vibor) || pod_vibor < 0 || pod_vibor > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери 0, 1 или 2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pod_vibor) {
        case 1:
            system("cls");
            demo_list_operations();
            break;
        case 2:
            system("cls");
            t3();
            break;
        case 0:
            return;
        }

        if (pod_vibor != 0) {
            std::cout << "\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task4() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 4 (LISTWORK22) ~~\n\n";
        std::cout << "\t1. Операции над списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери: ";
        while (!(std::cin >> pod_vibor) || pod_vibor < 0 || pod_vibor > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери 0, 1 или 2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pod_vibor) {
        case 1:
            system("cls");
            demo_list_operations();
            break;
        case 2:
            system("cls");
            t4();
            break;
        case 0:
            return;
        }

        if (pod_vibor != 0) {
            std::cout << "\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task5() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 5 (LISTWORK59) ~~\n\n";
        std::cout << "\t1. Операции над списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери: ";
        while (!(std::cin >> pod_vibor) || pod_vibor < 0 || pod_vibor > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери 0, 1 или 2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pod_vibor) {
        case 1:
            system("cls");
            demo_list_operations();
            break;
        case 2:
            system("cls");
            t5();
            break;
        case 0:
            return;
        }

        if (pod_vibor != 0) {
            std::cout << "\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}
void demo_stack_operations() {
    Stack s;
    int action;
    do {
        std::cout << "\n\t~~ Демонстрация операций над стеком ~~\n";
        std::cout << "\tСтек сейчас: ";
        if (s.is_empty()) std::cout << "пустой";
        else s.print();
        std::cout << "\n\n";
        std::cout << "\t1. Добавить элемент\n";
        std::cout << "\t2. Удалить элемент \n";
        std::cout << "\t3. Найти элемент\n";
        std::cout << "\t4. Посмотреть вершину\n";
        std::cout << "\t5. Показать адрес вершины\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери действие: ";
        while (!(std::cin >> action) || action < 0 || action > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери от 0 до 5... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (action) {
        case 1: {
            int x;
            std::cout << "\n\tВведи число для добавления: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            s.add(x);
            std::cout << "\n\tДобавлено: " << x;
            break;
        }
        case 2: {
            int x;
            if (s.pop(x)) {
                std::cout << "\n\tУдалено: " << x;
            }
            else {
                std::cout << "\n\tСтек пуст — удалять нечего!";
            }
            break;
        }
        case 3: {
            int x;
            std::cout << "\n\tВведи значение для поиска: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Node* p = s.find(x);
            if (p) {
                std::cout << "\n\tНайдено! Адрес: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 4: {
            int x;
            if (s.peek(x)) {
                std::cout << "\n\tВершина стека: " << x;
            }
            else {
                std::cout << "\n\tСтек пуст!";
            }
            break;
        }
        case 5: {
            Node* p = s.get_top();
            if (p) {
                std::cout << "\n\tАдрес вершины: " << p;
            }
            else {
                std::cout << "\n\tСтек пуст!";
            }
            break;
        }
        case 0:
            break;
        }

        if (action != 0) {
            std::cout << "\n\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (action != 0);
}
void demo_queue_operations() {
    Queue q;
    int action;
    do {
        std::cout << "\n\t~~ Демонстрация операций над очередью ~~\n";
        std::cout << "\tОчередь сейчас: ";
        if (q.is_empty()) std::cout << "пустая";
        else q.print();
        std::cout << "\n\n";
        std::cout << "\t1. Добавить в конец\n";
        std::cout << "\t2. Удалить из начала\n";
        std::cout << "\t3. Найти элемент\n";
        std::cout << "\t4. Показать начало\n";
        std::cout << "\t5. Показать конец\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери действие: ";
        while (!(std::cin >> action) || action < 0 || action > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери от 0 до 5... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (action) {
        case 1: {
            int x;
            std::cout << "\n\tВведи число для добавления: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            q.add(x);
            std::cout << "\n\tДобавлено в конец: " << x;
            break;
        }
        case 2: {
            int x;
            if (q.dequeue(x)) {
                std::cout << "\n\tУдалено из начала: " << x;
            }
            else {
                std::cout << "\n\tОчередь пуста — удалять нечего!";
            }
            break;
        }
        case 3: {
            int x;
            std::cout << "\n\tВведи значение для поиска: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            TNode* p = q.find(x);
            if (p) {
                std::cout << "\n\tНайдено! Адрес: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 4: {
            TNode* p = q.get_head();
            if (p) {
                std::cout << "\n\tАдрес начала: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tОчередь пуста!";
            }
            break;
        }
        case 5: {
            TNode* p = q.get_tail();
            if (p) {
                std::cout << "\n\tАдрес конца: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tОчередь пуста!";
            }
            break;
        }
        case 0:
            break;
        }

        if (action != 0) {
            std::cout << "\n\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (action != 0);
}
void demo_list_operations() {
    LinkedList l;
    int action;
    do {
        std::cout << "\n\t~~ Демонстрация операций над списком ~~\n";
        std::cout << "\tСписок сейчас: ";
        if (l.is_empty()) std::cout << "пустой";
        else l.print();
        std::cout << "\n\n";
        std::cout << "\t1. Добавить в конец\n";
        std::cout << "\t2. Удалить элемент\n";
        std::cout << "\t3. Найти элемент\n";
        std::cout << "\t4. Показать голову\n";
        std::cout << "\t5. Показать второй элемент\n";
        std::cout << "\t0. Назад\n";
        std::cout << "\n\tВыбери действие: ";
        while (!(std::cin >> action) || action < 0 || action > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( выбери от 0 до 5... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (action) {
        case 1: {
            int x;
            std::cout << "\n\tВведи число для добавления: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            l.add(x);
            std::cout << "\n\tДобавлено в конец: " << x;
            break;
        }
        case 2: {
            int x;
            std::cout << "\n\tВведи значение для удаления: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (l.remove(x)) {
                std::cout << "\n\tУдалено: " << x;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 3: {
            int x;
            std::cout << "\n\tВведи значение для поиска: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ListNode* p = l.find(x);
            if (p) {
                std::cout << "\n\tНайдено! Адрес: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 4: {
            ListNode* p = l.get_head();
            if (p) {
                std::cout << "\n\tАдрес головы: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tСписок пуст!";
            }
            break;
        }
        case 5: {
            ListNode* p = l.get_second();
            if (p) {
                std::cout << "\n\tАдрес второго элемента: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tВ списке меньше 2 элементов!";
            }
            break;
        }
        case 0:
            break;
        }

        if (action != 0) {
            std::cout << "\n\n\tНажми что нибудь для продолжения...";
            std::cin.get(); std::cin.get();
            system("cls");
        }
    } while (action != 0);
}

void fill_stack(Stack& s, int method, int n = 0) {
    if (method == 1) {//с клавиатуры
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cout << "\t  [" << (i + 1) << "]: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t  [" << (i + 1) << "]: Ошибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            s.add(x);
        }
    }
    else if (method == 2) {//рандомно
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            s.add(x);
        }
    }
    else if (method == 3) {//из файла
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
        int i = 0;
        while (file >> x) {
            std::cout << "\t  [" << (++i) << "]: " << x << "\n";
            s.add(x);
        }
        file.close();
    }
}

void fill_queue(Queue& q, int method, int n = 0) {
    if (method == 1) {//с клавиатуры
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cout << "\t  [" << (i + 1) << "]: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t  [" << (i + 1) << "]: Ошибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            q.add(x);
        }
    }
    else if (method == 2) {//рандомно
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            q.add(x);
        }
    }
    else if (method == 3) {//из файла
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
        int i = 0;
        while (file >> x) {
            std::cout << "\t  [" << (++i) << "]: " << x << "\n";
            q.add(x);
        }
        file.close();
    }
}
void fill_list(LinkedList& l, int method, int n = 0) {
    if (method == 1) {//с клавиатуры
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x;
            std::cout << "\t  [" << (i + 1) << "]: ";
            while (!(std::cin >> x)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t  [" << (i + 1) << "]: Ошибочка( нужно целое число... Давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            l.add(x);
        }
    }
    else if (method == 2) {//рандомно
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            l.add(x);
        }
    }
    else if (method == 3) {//из файла
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
        int i = 0;
        while (file >> x) {
            std::cout << "\t  [" << (++i) << "]: " << x << "\n";
            l.add(x);
        }
        file.close();
    }
}

void t1() {
    std::cout << "\n\t\t~~ Задание 1 (DYNAMIC3) ~~\n\n";
    Stack s;//создаём пустой стек
    std::cout << "\tКак заполнить стек?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    std::cout << "\n\tВыбери: ";
    int method;
    while (!(std::cin >> method) || method < 1 || method > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    if (method == 1 || method == 2) {
        std::cout << "\n\tСколько элементиков? ";
        while (!(std::cin >> n) || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( нужно >=1... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    fill_stack(s, method, n);
    std::cout << "\n\tИсходный стек: ";
    s.print();
    Node* p1 = s.get_top();
    std::cout << "\n\n\tАдрес вершинки стека (P1): " << p1 << "\n";
    std::cout << "\n\tВведи число D для добавления в стек: ";
    int d;
    while (!(std::cin >> d)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    s.add(d);//добавляем д
    Node* p2 = s.get_top();//указатель на новую вершинку
    std::cout << "\n\tНовый стек: ";
    s.print();
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tАдрес новой вершинки стека (P2): " << p2 << "\n";
    std::cout << "\tАдрес, на который ссылается новая вершинка (P2->next): " << p2->next << "\n";
}
void t2() {
    std::cout << "\n\t\t~~ Задание 2 (DYNAMIC24) ~~\n\n";
    Queue q1, q2;//создаём две очереди
    std::cout << "\tКак заполнить очереди?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    std::cout << "\n\tВыбери: ";
    int method;
    while (!(std::cin >> method) || method < 1 || method > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    if (method == 1 || method == 2) {
        std::cout << "\n\tСколько элементиков в каждой очереди? ";
        while (!(std::cin >> n) || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( нужно >=1... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\n\tЗаполняем первую очередь:\n";
    fill_queue(q1, method, n);
    std::cout << "\n\tЗаполняем вторую очередь:\n";
    fill_queue(q2, method, n);

    TNode* P1 = q1.get_head();//указатели на начало и конец
    TNode* P2 = q1.get_tail();
    TNode* P3 = q2.get_head();
    TNode* P4 = q2.get_tail();
    std::cout << "\n\tИсходные очередки:\n";
    std::cout << "\tПервая:  "; q1.print();
    std::cout << "\n\tВторая:  "; q2.print();
    std::cout << "\n\n\tИсходные указатели:\n";
    std::cout << "\tP1 (начало 1-й): " << P1 << "\n";
    std::cout << "\tP2 (конец 1-й):  " << P2 << "\n";
    std::cout << "\tP3 (начало 2-й): " << P3 << "\n";
    std::cout << "\tP4 (конец 2-й):  " << P4 << "\n";
    TNode* new_head = P1;//начало
    TNode* new_tail = nullptr;
    TNode* curr1 = P1;//текущие элементы из обеих очередок
    TNode* curr2 = P3;
    TNode* next1 = nullptr;
    TNode* next2 = nullptr;
    while (curr1 != nullptr && curr2 != nullptr) {//чередуем элементики
        next1 = curr1->next;//запоминаем
        next2 = curr2->next;
        curr1->next = curr2;//связываем первую со второй
        if (next1 != nullptr) {
            curr2->next = next1;
        }
        else {
            curr2->next = nullptr;
            new_tail = curr2;//конец. последний из второй очередки
        }
        curr1 = next1;//переходим дальше
        curr2 = next2;
    }
    if (curr1 != nullptr && new_tail == nullptr) {
        new_tail = P2;//если остались элементы из первой
    }
    if (new_tail == nullptr) {
        new_tail = P4;//на случай, если n=1
    }
    q1.detach();//отсоединяем узелки от исходных очередок
    q2.detach();
    std::cout << "\n\n\t~~ Результатик ~~\n";
    std::cout << "\tНовая очередь: ";
    TNode* current = new_head;
    if (!current) {
        std::cout << "пустая";
    }
    else {
        std::cout << current->data;
        current = current->next;
        while (current) {
            std::cout << " -> " << current->data;
            current = current->next;
        }
    }
    std::cout << "\n\n\tУказатели новой очереди:\n";
    std::cout << "\tНачало: " << new_head << "\n";
    std::cout << "\tКонец:   " << new_tail << "\n";
    std::cin.get();
}
void t3() {
    std::cout << "\n\t\t~~ Задание 3 (LISTWORK1) ~~\n\n";
    LinkedList list;//создаём список
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    std::cout << "\n\tВыбери: ";
    int method;
    while (!(std::cin >> method) || method < 1 || method > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    if (method == 1 || method == 2) {
        std::cout << "\n\tСколько элементиков? (минимум 2): ";
        while (!(std::cin >> n) || n < 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( нужно >=2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    fill_list(list, method, n);

    std::cout << "\n\tИсходный список: ";
    list.print();
    ListNode* p1 = list.get_head();//голова списка
    ListNode* p2 = list.get_second();//второй элементик
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tАдрес головы списка (P1): " << p1 << "\n";
    std::cout << "\tАдрес второго элементика (P2): " << p2 << "\n";
    if (p2) {
        std::cout << "\tЗначение второго элементика: " << p2->data << "\n";
    }
    std::cin.get();
}

void t4() {
    std::cout << "\n\t\t~~ Задание 4 (LISTWORK22) ~~\n\n";
    LinkedList list;//создаём список
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    std::cout << "\n\tВыбери: ";
    int method;
    while (!(std::cin >> method) || method < 1 || method > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    if (method == 1 || method == 2) {
        std::cout << "\n\tСколько элементиков? (минимум 2): ";
        while (!(std::cin >> n) || n < 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( нужно >=2... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    fill_list(list, method, n);

    std::cout << "\n\tВведи значение M для вставки: ";
    int M;
    while (!(std::cin >> M)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tИсходный список: ";
    list.print();
    ListNode* tail_before = list.get_head();//адрес последнего элементика до вставки
    if (tail_before) {
        while (tail_before->next) {
            tail_before = tail_before->next;
        }
    }
    ListNode* tail_after = list.every_second(M);//вставка после каждого второго
    std::cout << "\n\tАдрес последнего элементика до вставки: " << tail_before << "\n";
    std::cout << "\tЗначение: " << tail_before->data << "\n";
    std::cout << "\tАдрес последнего элементика после вставки: " << tail_after << "\n";
    std::cout << "\tЗначение: " << tail_after->data << "\n";
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tСписок после вставки M=" << M << " после каждого второго элементика:\n\t";
    list.print();
    std::cin.get();
}
void t5() {
    std::cout << "\n\t\t~~ Задание 5 (LISTWORK59) ~~\n\n";
    LinkedList list;//создаём список
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    std::cout << "\n\tВыбери: ";
    int method;
    while (!(std::cin >> method) || method < 1 || method > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( выбери 1, 2 или 3... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    if (method == 1 || method == 2) {
        std::cout << "\n\tСколько элементиков? (минимум 1): ";
        while (!(std::cin >> n) || n < 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tОшибочка( нужно >=1... Давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    fill_list(list, method, n);

    std::cout << "\n\tВведи K (после каждого K-го элемента): ";
    int K;
    while (!(std::cin >> K) || K <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( K должно быть положительным... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n\tВведи значение M для вставки: ";
    int M;
    while (!(std::cin >> M)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n\tИсходный список: ";
    list.print();
    ListNode* tail_before = list.get_head();//адрес последнего элементика до вставки
    if (tail_before) {
        while (tail_before->next) {
            tail_before = tail_before->next;
        }
    }
    ListNode* p2 = list.every_k(K, M);//вставка после каждого K-го
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tСписок после вставки M=" << M << " после каждого " << K << "-го элементика:\n\t";
    list.print();
    std::cout << "\n\n\tАдрес последнего элементика до вставки: " << tail_before << "\n";
    if (tail_before) {
        std::cout << "\tЗначение: " << tail_before->data << "\n";
    }
    std::cout << "\tАдрес последнего элементика после вставки: " << p2 << "\n";
    if (p2) {
        std::cout << "\tЗначение: " << p2->data << "\n";
    }
    std::cin.get();
}