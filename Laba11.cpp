#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <fstream>
#include <random>
#include "circular_list.h"
#include "circular_doubly_list.h"
#include "doubly_list.h"
#include "circular_string_list.h"
void menu_task1(); 
void menu_task2(); 
void menu_task3();
void menu_task4();
void menu_task5();
void demo_doubly_list_operations();
void demo_circular_list_operations();
void t1();
void t2();
void t3();
void t4();
void t5();
int get_int(const std::string& prompt = "") { // ввод целого числа с проверкой
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

int get_int_in_range(const std::string& prompt, int min_val, int max_val) { //ввод числа в диапазоне
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min_val && value <= max_val) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << "\n\tОшибочка( выбери от " << min_val << " до " << max_val << "... Давай по новой: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void fill_circular(CircularList& list, int method, int n = 0) { //заполнение циклич списка
    if (method == 1) { // с клавиатуры
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x = get_int("\t  [" + std::to_string(i + 1) + "]: ");
            list.push_back(x);
        }
    }
    else if (method == 2) { // случайно
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            list.push_back(x);
        }
    }
    else if (method == 3) { // из файла
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
            list.push_back(x);
        }
        file.close();
    }
}

void fill_circular_doubly(CircularDoublyList& list, int method, int n = 0) { // заполнение цикл двусвязного списка
    if (method == 1) {
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x = get_int("\t  [" + std::to_string(i + 1) + "]: ");
            list.push_back(x);
        }
    }
    else if (method == 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            list.push_back(x);
        }
    }
    else if (method == 3) {
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
            list.push_back(x);
        }
        file.close();
    }
}

void fill_doubly(DoublyList& list, int method, int n = 0) { // заполнение двусвязо списка
    if (method == 1) {
        std::cout << "\n\tВведи " << n << " чиселок:\n";
        for (int i = 0; i < n; ++i) {
            int x = get_int("\t  [" + std::to_string(i + 1) + "]: ");
            list.push_back(x);
        }
    }
    else if (method == 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        std::cout << "\n\tГенерим " << n << " случайных чиселок от 1 до 100:\n";
        for (int i = 0; i < n; ++i) {
            int x = dis(gen);
            std::cout << "\t  [" << (i + 1) << "]: " << x << "\n";
            list.push_back(x);
        }
    }
    else if (method == 3) {
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
            list.push_back(x);
        }
        file.close();
    }
}

void menu_task1() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 1 (ListWork66) ~~\n\n";
        std::cout << "\t1. Операции над циклическим списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        pod_vibor = get_int_in_range("\n\tВыбери: ", 0, 2);
        system("cls");
        switch (pod_vibor) {
        case 1: demo_circular_list_operations(); break;
        case 2: t1(); break;
        }
        if (pod_vibor != 0 && pod_vibor != 1) {
            std::cout << "\n\tНажми что нибудь для возврата...";
            std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task2() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 2 (ListWork42) ~~\n\n";
        std::cout << "\t1. Операции над циклическим двусвязным списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        pod_vibor = get_int_in_range("\n\tВыбери: ", 0, 2);
        system("cls");
        switch (pod_vibor) {
        case 1: demo_doubly_list_operations(); break;
        case 2: t2(); break;
        }
        if (pod_vibor != 0 && pod_vibor != 1) {
           // std::cout << "\n\tНажми что нибудь для возврата...";
            std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task3() {
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 3 (ListWork43) ~~\n\n";
        std::cout << "\t1. Операции над двусвязным списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        pod_vibor = get_int_in_range("\n\tВыбери: ", 0, 2);
        system("cls");
        switch (pod_vibor) {
        case 1: demo_doubly_list_operations(); break;
        case 2: t3(); break;
        }
        if (pod_vibor != 0 && pod_vibor != 1) {
           // std::cout << "\n\tНажми что нибудь для возврата...";
            std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task4() { // подменю задания 4
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 4 (ListWork46) ~~\n\n";
        std::cout << "\t1. Операции над двусвязным списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        pod_vibor = get_int_in_range("\n\tВыбери: ", 0, 2);
        system("cls");
        switch (pod_vibor) {
        case 1: demo_doubly_list_operations(); break;
        case 2: t4(); break;
        }
        if (pod_vibor != 0 && pod_vibor != 1) {
            std::cout << "\n\tНажми что нибудь для возврата...";
            std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void menu_task5() { 
    int pod_vibor;
    do {
        std::cout << "\n\t\t~~ Задание 5 (Считалка) ~~\n\n";
        std::cout << "\t1. Операции над циклическим списком\n";
        std::cout << "\t2. Решение задания\n";
        std::cout << "\t0. Назад\n";
        pod_vibor = get_int_in_range("\n\tВыбери: ", 0, 2);
        system("cls");
        switch (pod_vibor) {
        case 1: demo_circular_list_operations(); break;
        case 2: t5(); break;
        }
        if (pod_vibor != 0 && pod_vibor != 1) {
          //  std::cout << "\n\tНажми что нибудь для возврата...";
            std::cin.get();
            system("cls");
        }
    } while (pod_vibor != 0);
}

void t1() {
    std::cout << "\n\t\t~~ Задание 1 (ListWork66) ~~\n\n";
    CircularList list;
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int_in_range("\n\tВыбери: ", 1, 3);
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_int("\n\tСколько элементиков? ");
        while (n <= 0) {
            std::cout << "\n\tОшибочка( нужно >=1\n";
            n = get_int("\n\tДавай по новой: ");
        }
    }
    fill_circular(list, method, n);
    std::cout << "\n\tИсходный список: ";
    list.print();
    std::string filename;
    std::cout << "\n\n\tВведи имя файла для вывода: ";
    std::cin >> filename;
    list.listwork66(filename);
    std::cout << "\n\tГотово! Список теперь пуст.\n";
    std::cin.get();
}

void t2() { 
    std::cout << "\n\t\t~~ Задание 2 (ListWork42) ~~\n\n";
    CircularDoublyList list;
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int_in_range("\n\tВыбери: ", 1, 3);
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_int("\n\tСколько элементиков? ");
        while (n <= 0) {
            std::cout << "\n\tОшибочка( нужно >=1\n";
            n = get_int("\n\tДавай по новой: ");
        }
    }
    fill_circular_doubly(list, method, n);
    Node* original_head = list.get_head();
    Node* original_tail = list.get_tail();
    std::cout << "\n\tИсходный список: ";
    list.print();
    if (original_head) {
        std::cout << "\n\tАдрес первого элемента (исходный): " << original_head;
        std::cout << "\n\tАдрес последнего элемента (исходный): " << original_tail;
        std::cout << " (значение: " << original_tail->data << ")";
    }
    else {
        std::cout << "\n\tСписок пуст.";
    }
    Node* new_tail = list.listwork42();
    std::cout << "\n\n\tСписок после удаления:\n\t";
    if (list.is_empty()) {
        std::cout << "пустой";
    }
    else {
        list.print();
    }
    if (new_tail) {
        std::cout << "\n\n\tАдрес последнего элемента (после удаления): " << new_tail;
        std::cout << " (значение: " << new_tail->data << ")";
    }
    else {
        std::cout << "\n\n\tСписок пуст — последнего элемента нет.";
    }
    std::cout << "\n\tНажми что нибудь для возврата...";
    std::cin.get();
}

void t3() {
    std::cout << "\n\t\t~~ Задание 3 (ListWork43) ~~\n\n";
    DoublyList list;
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int_in_range("\n\tВыбери: ", 1, 3);
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_int("\n\tСколько элементиков? ");
        while (n <= 0) {
            std::cout << "\n\tОшибочка( нужно >=1\n";
            n = get_int("\n\tДавай по новой: ");
        }
    }
    fill_doubly(list, method, n);
    DNode* orig_head = list.get_head();
    DNode* orig_tail = list.get_tail();
    std::cout << "\n\tИсходный список: ";
    list.print();
    if (orig_head) {
        std::cout << "\n\tИсходный первый элемент: адрес = " << orig_head << ", значение = " << orig_head->data;
        std::cout << "\n\tИсходный последний элемент: адрес = " << orig_tail << ", значение = " << orig_tail->data;
    }
    else {
        std::cout << "\n\tСписок пуст.";
    }
    DNode* new_head = list.listwork43();
    DNode* new_tail = list.get_tail();
    std::cout << "\n\n\tСписок после перегруппировки:\n\t";
    list.print();
    if (new_head) {
        std::cout << "\n\n\tНовый первый элемент: адрес = " << new_head << ", значение = " << new_head->data;
        std::cout << "\n\tНовый последний элемент: адрес = " << new_tail << ", значение = " << new_tail->data;
    }
    else {
        std::cout << "\n\n\tСписок стал пустым.";
    }
    //std::cout << "\n\tНажми что нибудь для возврата...";
    std::cin.get();
}

void t4() {
    std::cout << "\n\t\t~~ Задание 4 (ListWork46) ~~\n\n";
    DoublyList list;
    std::cout << "\tКак заполнить список?\n";
    std::cout << "\t1. С клавиатуры\n\t2. Случайно\n\t3. Из файла\n";
    int method = get_int_in_range("\n\tВыбери: ", 1, 3);
    int n = 0;
    if (method == 1 || method == 2) {
        n = get_int("\n\tСколько элементиков? ");
        while (n <= 0) {
            std::cout << "\n\tОшибочка( нужно >=1\n";
            n = get_int("\n\tДавай по новой: ");
        }
    }
    fill_doubly(list, method, n);
    DNode* P1 = list.get_head();
    DNode* P2 = list.get_tail();
    std::cout << "\n\tИсходный список: ";
    list.print();
    if (P1) {
        std::cout << "\n\tP1 (первый): адрес:" << P1 << ", значение:" << P1->data;
        std::cout << "\n\tP2 (последний): адрес:" << P2 << ", значение:" << P2->data;
    }
    else {
        std::cout << "\n\tСписок пуст.";
    }
    DNode* barrier = create_barrier_and_link(P1, P2);
    std::cout << "\n\n\tЦиклический список с барьерным элементом:\n\t";
    if (barrier->next == barrier) {
        std::cout << "[0] (только барьер)";
    }
    else {
        DNode* cur = barrier;
        do {
            if (cur == barrier) {
                std::cout << "[0]";
            }
            else {
                std::cout << cur->data;
            }
            cur = cur->next;
            if (cur != barrier) std::cout << " <-> ";
        } while (cur != barrier);
    }
    std::cout << "\n\n\tАдрес барьерного элемента: " << barrier;
    std::cout << "\n\tЗначение: " << barrier->data;
    std::cout << "\n\tБарьер->next = " << barrier->next;
    std::cout << "\n\tБаоьер->prev = " << barrier->prev;
    if (P1) {
      //  std::cout << "\n\tПроверка: P1->prev == barrier - " << (P1->prev == barrier ? "OK" : "FAIL");
        //std::cout << "\n\tПроверка: P2->next == barrier - " << (P2->next == barrier ? "OK" : "FAIL");
    }
    else {
        std::cout << "\n\tСписок был пуст — барьер ссылается сам на себя.";
    }
    list.disconnect();
   // std::cout << "\n\tНажми что нибудь для возврата...";
    std::cin.get();
}

void t5() {
    std::cout << "\n\t\t~~ Задание 5 (Считалка) ~~\n\n";
    std::string input_file, output_file;
    std::cout << "\tВведи имя входного файла: ";
    std::cin >> input_file;
    std::cout << "\tВведи имя выходного файла: ";
    std::cin >> output_file;
    std::ifstream in(input_file);
    if (!in.is_open()) {
        std::cout << "\n\tОшибочка( файл \"" << input_file << "\" не найден!\n";
        std::cout << "\n\tНажми что нибудь для возврата...";
        std::cin.get();
        return;
    }
    int k;
    in >> k;
    in.ignore();
    CircularStringList list;
    std::string name;
    while (std::getline(in, name)) {
        if (!name.empty()) {
            list.push_back(name);
        }
    }
    in.close();
    if (list.is_empty()) {
        std::cout << "\n\tСписок детей пуст.\n";
        std::cout << "\n\tНажми что нибудь для возврата...";
        std::cin.get();
        return;
    }
    std::cout << "\n\tСчиталка: " << k << " слов\n";
    std::cout << "\n\tДеинсталируются: ";
    list.josephus(k, output_file);
    std::cout << "\n\tНажми что нибудь для возврата...";
    std::cin.get();
}

void demo_circular_list_operations() { // демо цикл списка
    CircularList list;
    int action;
    do {
        std::cout << "\n\t~~ Демонстрация операций над циклическим списком ~~\n";
        std::cout << "\tСписок сейчас: ";
        if (list.is_empty()) std::cout << "пустой";
        else list.print();
        std::cout << "\n\n";
        std::cout << "\t1. Добавить в конец\n";
        std::cout << "\t2. Удалить по значению\n";
        std::cout << "\t3. Найти элемент\n";
        std::cout << "\t4. Показать голову\n";
        std::cout << "\t5. Демонстрация копирования\n";
        std::cout << "\t0. Назад\n";
        action = get_int_in_range("\n\tВыбери действие: ", 0, 5);
        system("cls");
        switch (action) {
        case 1: {
            int x = get_int("\n\tВведи число для добавления: ");
            list.push_back(x);
            std::cout << "\n\tДобавлено: " << x;
            break;
        }
        case 2: {
            int x = get_int("\n\tВведи значение для удаления: ");
            if (list.remove(x)) {
                std::cout << "\n\tУдалено: " << x;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 3: {
            int x = get_int("\n\tВведи значение для поиска: ");
            CNode* p = list.find(x);
            if (p) {
                std::cout << "\n\tНайдено! Адрес: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 4: {
            CNode* p = list.get_head();
            if (p) {
                std::cout << "\n\tАдрес головы: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tСписок пуст!";
            }
            break;
        }
        case 5: {
            if (list.is_empty()) {
                std::cout << "\n\tСначала заполни список!";
                break;
            }
            std::cout << "\n\tИсходный: "; list.print();
            CircularList copy1(list);
            std::cout << "\n\tКопия (конструктор): "; copy1.print();
            CircularList copy2;
            copy2 = list;
            std::cout << "\n\tКопия (присваивание): "; copy2.print();
            list.push_back(9112);
            std::cout << "\n\tПосле добавления 9112 в исходный:";
            std::cout << "\n\tИсходный: "; list.print();
            std::cout << "\n\tКопия 1: "; copy1.print();
            std::cout << "\n\tКопия 2: "; copy2.print();
            break;
        }
        }
        if (action != 0) {
            std::cout << "\n\n\tНажми что нибудь для продолжения...";
            std::cin.get();
            system("cls");
        }
    } while (action != 0);
}

void demo_doubly_list_operations() { // демон двусвязного
    DoublyList list;
    int action;
    do {
        std::cout << "\n\t~~ Демонстрация операций над двусвязным списком ~~\n";
        std::cout << "\tСписок сейчас: ";
        if (list.is_empty()) std::cout << "пустой";
        else list.print();
        std::cout << "\n\n";
        std::cout << "\t1. Добавить в начало\n";
        std::cout << "\t2. Добавить в конец\n";
        std::cout << "\t3. Удалить по значению\n";
        std::cout << "\t4. Найти элемент\n";
        std::cout << "\t5. Показать голову/хвост\n";
        std::cout << "\t6. Демонстрация копирования\n";
        std::cout << "\t0. Назад\n";
        action = get_int_in_range("\n\tВыбери действие: ", 0, 6);
        system("cls");
        switch (action) {
        case 1: {
            int x = get_int("\n\tВведи число для добавления в начало: ");
            list.push_front(x);
            std::cout << "\n\tДобавлено в начало: " << x;
            break;
        }
        case 2: {
            int x = get_int("\n\tВведи число для добавления в конец: ");
            list.push_back(x);
            std::cout << "\n\tДобавлено в конец: " << x;
            break;
        }
        case 3: {
            int x = get_int("\n\tВведи значение для удаления: ");
            if (list.remove(x)) {
                std::cout << "\n\tУдалено: " << x;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 4: {
            int x = get_int("\n\tВведи значение для поиска: ");
            DNode* p = list.find(x);
            if (p) {
                std::cout << "\n\tНайдено! Адрес: " << p << ", значение: " << p->data;
            }
            else {
                std::cout << "\n\tНе найдено(";
            }
            break;
        }
        case 5: {
            DNode* head = list.get_head();
            DNode* tail = list.get_tail();
            if (head) {
                std::cout << "\n\tГолова: " << head << " (" << head->data << ")";
                std::cout << "\n\tХвост: " << tail << " (" << tail->data << ")";
            }
            else {
                std::cout << "\n\tСписок пуст!";
            }
            break;
        }
        case 6: {
            if (list.is_empty()) {
                std::cout << "\n\tСначала заполни список!";
                break;
            }
            std::cout << "\n\tИсходный: "; list.print();
            DoublyList copy1(list);
            std::cout << "\n\tКопия (конструктор): "; copy1.print();
            DoublyList copy2;
            copy2 = list;
            std::cout << "\n\tКопия (присваивание): "; copy2.print();
            list.push_back(9112);
            std::cout << "\n\tПосле добавления 9112 в исходный:";
            std::cout << "\n\tИсходный: "; list.print();
            std::cout << "\n\tКопия 1: "; copy1.print();
            std::cout << "\n\tКопия 2: "; copy2.print();
            break;
        }
        }
        if (action != 0) {
            std::cout << "\n\n\tНажми что нибудь для продолжения...";
            std::cin.get();
            system("cls");
        }
    } while (action != 0);
}

int main() { 
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Russian");
    int vibor;
    do {
        std::cout << "\t1. Задание 1 - Циклический список (ListWork66)\n";
        std::cout << "\t2. Задание 2 - Циклический двусвязный список (ListWork42)\n";
        std::cout << "\t3. Задание 3 - Перегруппировка списка (ListWork43)\n";
        std::cout << "\t4. Задание 4 - Барьерный элемент (ListWork46)\n";
        std::cout << "\t5. Задание 5 - Считалка (1)\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        vibor = get_int_in_range("\n\tВыбери: ", 0, 5);
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
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            system("cls");
        }
    } while (vibor != 0);
    return 0;
}