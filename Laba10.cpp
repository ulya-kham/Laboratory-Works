#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
void t1();
void t2();
void t3();
void t4();
void t5();
int main() {
    std::setlocale(LC_ALL, "Russian");
    int vibor;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа №10 ~~\n\n";
        std::cout << "\t1. Задание 1 - Стек: добавить элемент (Dynamic3)\n";
        std::cout << "\t2. Задание 2 - Очередь: объединить с чередованием (Dynamic24)\n";
        std::cout << "\t3. Задание 3 - Список: второй элемент (ListWork1)\n";
        std::cout << "\t4. Задание 4 - Список: вставить после каждого второго (ListWork22)\n";
        std::cout << "\t5. Задание 5 - Список: вставить после каждого K-го (ListWork59)\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        std::cout << "\n\tВыберите задачу: ";
        while (!(std::cin >> vibor)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\tНу нет, цифры от 0 до 5... А ты другое ввёл, давай по новой: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (vibor < 0 || vibor > 5) {
            std::cout << "\n\tНу нет, цифры от 0 до 5... А ты другое ввёл, давай по новой: ";
            while (!(std::cin >> vibor)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\tНу нет, цифры от 0 до 5... А ты другое ввёл, давай по новой: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("cls");
        switch (vibor) {
        case 1:
            t1();
            break;
        case 2:
            t2();
            break;
        case 3:
            t3();
            break;
        case 4:
            t4();
            break;
        case 5:
            t5();
            break;
        case 0:
            std::cout << "\n\tМожешь не возвращаться) Пока-пока))\n\n";
            break;
        }
        if (vibor != 0) {
            std::cout << "\n\tНажми что-нибудь для продолжения... Иначе мир взорвется ";
            std::cin.get();
            system("cls");
        }
    } while (vibor != 0);
    return 0;
}

void t1() {
    std::cout << "\n\t\t~~ Задание 1 (DYNAMIC3) ~~\n\n";
    Stack s;//создаем пустой стек
    std::cout << "\tСколько элементиков хочешь ввести? ";
    int n;
    if (!(std::cin >> n)) {
        std::cout << "\n\tОшибочка( нужно ввести целое число\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (n <= 0) {
        std::cout << "\n\tОшибочка( стек должен быть непустым, введите число >= 1\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tВведи " << n << " целых чиселок:\n";//вводим элементы и добавляем в стек
    for (int i = 0; i < n; i++) {
        std::cout << "\t  [" << (i + 1) << "]: ";
        int value;
        if (!(std::cin >> value)) {
            std::cout << "\n\tОшибочка( нужно ввести целое число(\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        s.add(value);//добавка
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tИсходный стек: ";
    s.print();//показываем
    Node* p1 = s.get_top();
    std::cout << "\n\n\tАдрес вершинки стека (P1): " << p1 << "\n";
    std::cout << "\n\tВведи число D для добавления в стек: ";
    int d;
    if (!(std::cin >> d)) {
        std::cout << "\n\tОшибочка( нужно ввести целое число\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    s.add(d);//добавляем д
    Node* p2 = s.get_top();//указвтель на новую вершинку
    std::cout << "\n\tНовый стек: ";
    s.print();
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tАдрес новой вершинки стека (P2): " << p2 << "\n";
    std::cout << "\tАдрес, на который ссылается новая вершинка (P2->next): " << p2->next << "\n";
}

void t2() {
    std::cout << "\n\t\t~~ Задание 2 (DYNAMIC24) ~~\n\n";
    Queue q1, q2;//создаём две очереди
    std::cout << "\tСколько элементиков в каждой очереди? ";
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "\n\tОшибочка( введи положительное целое число\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tВведи " << n << " чиселок для первой очереди:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "\t  [" << (i + 1) << "]: ";
        if (!(std::cin >> x)) {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cout << "\n\tНажми Enter для продолжения...";
            std::cin.get(); std::cin.get();
            return;
        }
        q1.add(x);
    }
    std::cout << "\n\tВведи " << n << " чиселок для второй очередки:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "\t  [" << (i + 1) << "]: ";
        if (!(std::cin >> x)) {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cout << "\n\tНажми Enter для продолжения...";
            std::cin.get(); std::cin.get();
            return;
        }
        q2.add(x);
    }
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
    std::cout << "\tСколько элементиков хочешь ввести? (минимум 2): ";
    int n;
    if (!(std::cin >> n) || n < 2) {
        std::cout << "\n\tОшибочка( нужно ввести число >= 2\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tВведи " << n << " целых чиселок:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "\t  [" << (i + 1) << "]: ";
        if (!(std::cin >> x)) {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cout << "\n\tНажми Enter для продолжения...";
            std::cin.get(); std::cin.get();
            return;
        }
        list.add(x);
    }
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
    std::cout << "\tСколько элементиков хочешь ввести? (минимум 2): ";
    int n;
    if (!(std::cin >> n) || n <= 1) {
        std::cout << "\n\tОшибочка( введи число >= 2\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tВведи " << n << " целых чиселок:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "\t  [" << (i + 1) << "]: ";
        if (!(std::cin >> x)) {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cout << "\n\tНажми Enter для продолжения...";
            std::cin.get(); std::cin.get();
            return;
        }
        list.add(x);
    }
    std::cout << "\n\tВведи значение M для вставки: ";
    int M;
    if (!(std::cin >> M)) {
        std::cout << "\n\tОшибочка( нужно целое число\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
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
    std::cout << "\tСколько элементиков хочешь ввести? (минимум 1): ";
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "\n\tОшибочка( введи положительное число\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\tВведи " << n << " целых чиселок:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "\t  [" << (i + 1) << "]: ";
        if (!(std::cin >> x)) {
            std::cout << "\n\tОшибочка( нужно целое число\n";
            std::cout << "\n\tНажми Enter для продолжения...";
            std::cin.get(); std::cin.get();
            return;
        }
        list.add(x);
    }
    std::cout << "\n\tВведи K (через сколько вводить): ";
    int K;
    if (!(std::cin >> K) || K <= 0) {
        std::cout << "\n\tОшибочка( K должно быть положительным\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
    }
    std::cout << "\n\tВведи значение M для вставки: ";
    int M;
    if (!(std::cin >> M)) {
        std::cout << "\n\tОшибочка( нужно целое число\n";
        std::cout << "\n\tНажми Enter для продолжения...";
        std::cin.get(); std::cin.get();
        return;
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
    ListNode* p2 = list.every_k(K, M);//вставка после каждого к
    std::cout << "\n\n\t~~ Результатик: ~~\n";
    std::cout << "\n\tСписок после вставки" << M << " после каждого " << K << "-го элементика:\n\t";
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