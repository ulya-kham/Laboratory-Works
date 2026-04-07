#include <iostream>
#include <limits>
#include <string>
#include "task1.h"
#include "task2.h"
#include "utils.h"
#include "task3.h"
#include "task4.h"
int get_int(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            else {
                std::cout << "\n\tОшибочка( выбери от " << min << " до " << max << "!\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "\n\tОшибочка( нужно целое число... Давай по новой: ";
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
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\n\t\t~~ Лабораторная работа №15 (ООП) ~~\n\n";
        std::cout << "\t1. Задача 1 – Точка\n";
        std::cout << "\t2. Задача 2 – Линия\n";
        std::cout << "\t3. Задача 3 – Студент\n";
        std::cout << "\t4. Задача 4 – Точка и Линия\n";
        std::cout << "\t5. Задача 5 – Длина Линии\n";
        std::cout << "\t0. Отпустить и забыть)\n";
        choice = get_int("\n\tВыбери задание: ", 0, 5);
        system("cls");
        switch (choice) {
        case 1: menu_task1(); break;
        case 2: menu_task2(); break;
        case 3: menu_task3(); break;
        case 4: menu_task4(); break;
        case 5: menu_task5(); break;
        case 0: std::cout << "\n\tМожешь не возвращаться) Пока-пока))\n\n"; break;
        default: std::cout << "\n\tОшибочка( выбери от 0 до 5!\n";
        }
        if (choice != 0) {
            std::cout << "\n\tНажми что нибудь для возврата в меню...";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
    } while (choice != 0);
    return 0;
}
void menu_task1() {
    int sub_choice;
    do {
        std::cout << "\n\t~~ Задача 1 – Точка ~~\n\n";
        std::cout << "\t1. Решение задачи\n";
        std::cout << "\t2. Демонстрация класса\n";
        std::cout << "\t3. Назад в главное меню\n";
        sub_choice = get_int("\n\tВыбери: ", 1, 3);
        system("cls");
        switch (sub_choice) {
        case 1: {
            std::cout << "\n\t~~ Решение задачи 1 ~~\n";
            std::cout << "\n\tСоздаём три точки с разными координатами.\n";
            double x1 = get_double("\tВведи X1: ");
            double y1 = get_double("\tВведи Y1: ");
            double x2 = get_double("\n\tВведи X2: ");
            double y2 = get_double("\tВведи Y2: ");
            double x3 = get_double("\n\tВведи X3: ");
            double y3 = get_double("\tВведи Y3: ");
            Point p1(x1, y1);
            Point p2(x2, y2);
            Point p3(x3, y3);
            std::cout << "\n\tТекстовое представление точек:\n";
            p1.print();
            p2.print();
            p3.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "\n\t~~ Демонстрация класса Точка ~~\n";
            std::cout << "\n\t1. Создаём точку (конструктор по умолчанию)";
            Point p1;
            std::cout << "\n\tРезультат: ";
            p1.print();
            double x = get_double("\n\t2. Введи X для новой точки: ");
            double y = get_double("\tВведи Y для новой точки: ");
            std::cout << "\tСоздаём вторую точку (" << x << ", " << y << ")";
            Point p2(x, y);
            std::cout << "\n\tРезультатик: ";
            p2.print();
            std::cout << "\n\t3. Создаём третью точку (копия второй)";
            Point p3 = p2;
            std::cout << "\n\tРезультатик: ";
            p3.print();
            std::cout << "\n\t4. Создаём пустую точку, и присваиваем ей третью";
            Point p4;
            std::cout << "\n\tДо присваивания: ";
            p4.print();
            p4 = p3;
            std::cout << "\tПосле присваивания: ";
            p4.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 3: break;
        default:
            std::cout << "\n\tОшибочка( выбери 1, 2 или 3!\n";
            std::cin.get();
            std::cin.get();
        }
        if (sub_choice != 3) {
            system("cls");
        }
    } while (sub_choice != 3);
}
void menu_task2() {
    int sub_choice;
    do {
        std::cout << "\n\t~~ Задача 2 – Линия ~~\n\n";
        std::cout << "\t1. Решение задачи\n";
        std::cout << "\t2. Демонстрация класса\n";
        std::cout << "\t3. Назад в главное меню\n";
        sub_choice = get_int("\n\tВыбери: ", 1, 3);
        system("cls");
        switch (sub_choice) {
        case 1: {
            std::cout << "\n\t~~ Решение задачи 2 ~~\n";
            Line line1(Point(1, 3), Point(23, 8));
            Line line2(Point(5, 10), Point(25, 10));
            Line line3(line1.get_start(), line2.get_end());
            std::cout << "\n\tИсходные линии:\n";
            std::cout << "\tЛиния 1: "; line1.print();
            std::cout << "\tЛиния 2: "; line2.print();
            std::cout << "\tЛиния 3: "; line3.print();
            std::cout << "\n\t4. Введи новые координаты для Линии 1 (начало и конец):\n";
            double x1s = get_double("\tНачало X: ");
            double y1s = get_double("\tНачало Y: ");
            double x1e = get_double("\tКонец X: ");
            double y1e = get_double("\tКонец Y: ");
            std::cout << "\n\tВведи новые координаты для Линии 2 (начало и конец):\n";
            double x2s = get_double("\tНачало X: ");
            double y2s = get_double("\tНачало Y: ");
            double x2e = get_double("\tКонец X: ");
            double y2e = get_double("\tКонец Y: ");
            line1.set_start(Point(x1s, y1s));
            line1.set_end(Point(x1e, y1e));
            line2.set_start(Point(x2s, y2s));
            line2.set_end(Point(x2e, y2e));
            line3.set_start(line1.get_start());
            line3.set_end(line2.get_end());
            std::cout << "\n\tПосле обновления:\n";
            std::cout << "\tЛиния 1: "; line1.print();
            std::cout << "\tЛиния 2: "; line2.print();
            std::cout << "\tЛиния 3: "; line3.print();
            std::cout << "\n\t5. Изменяем конец первой линии (начало не трогаем),\n\tчтобы третья линия не изменилась:\n";
            double x1e_new = get_double("\tНовый конец X: ");
            double y1e_new = get_double("\tНовый конец Y: ");
            line1.set_end(Point(x1e_new, y1e_new));
            std::cout << "\n\tПосле изменения Линия 1 (только конец):\n";
            std::cout << "\tЛиния 1: "; line1.print();
            std::cout << "\tЛиния 3 (не изменилась): "; line3.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "\n\t~~ Демонстрация класса Линия ~~\n";
            std::cout << "\n\t1. Создаём Линию 1 (констурктор по умолчанию)";
            Line l1;
            std::cout << "\n\tРезультатик: ";
            l1.print();
            double x1 = get_double("\n\t2. Введи X начала: ");
            double y1 = get_double("\tВведи Y начала: ");
            double x2 = get_double("\tВведи X конца: ");
            double y2 = get_double("\tВведи Y конца: ");
            Point p1(x1, y1), p2(x2, y2);
            Line l2(p1, p2);
            std::cout << "\tСоздаём Линию 2 от (" << x1 << ";" << y1 << ") до (" << x2 << ";" << y2 << ")...";
            std::cout << "\n\tРезультатик: ";
            l2.print();
            std::cout << "\n\t3. Создаём Линию 3 ( копия Линии 2)";
            Line l3 = l2;
            std::cout << "\n\tРезультатик: ";
            l3.print();
            std::cout << "\n\t4. Создаём Линию 4 (пустую), присваиваем ей Линию 3";
            Line l4;
            std::cout << "\n\tДо присваивания: ";
            l4.print();
            l4 = l3;
            std::cout << "\tПосле присваивания: ";
            l4.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 3: break;
        default:
            std::cout << "\n\tОшибочка( выбери 1, 2 или 3!\n";
            std::cin.get();
            std::cin.get();
        }
        if (sub_choice != 3) {
            system("cls");
        }
    } while (sub_choice != 3);
}
void menu_task3() {
    setlocale(LC_ALL, "Russian");
    int sub_choice;
    do {
        std::cout << "\n\t~~ Задача 3 – Студент ~~\n\n";
        std::cout << "\t1. Решение задачи\n";
        std::cout << "\t2. Демонстрация класса\n";
        std::cout << "\t3. Назад в главное меню\n";
        sub_choice = get_int("\n\tВыбери: ", 1, 3);
        system("cls");
        switch (sub_choice) {
        case 1: {
            std::cout << "\n\t~~ Решение задачи 3 ~~\n";
            Student vasya("Вася", { 3, 4, 5 });
            std::cout << "\n\t1. Создан студент Вася:\n";
            vasya.print();
            Student petya("Петя", vasya.get_grades());
            std::cout << "\n\t2. Создан студент Петя (оценки скопированы от Васи):\n";
            petya.print();
            std::vector<int> petya_grades = petya.get_grades();
            if (!petya_grades.empty()) {
                petya_grades[0] = 5;
                petya.set_grades(petya_grades);
            }
            std::cout << "\n\t3. Изменена первая оценка Пети на 5.\n";
            std::cout << ""; vasya.print();
            std::cout << ""; petya.print();
            std::cout << "\n\tОценки хранятся в векторе (по значению),\n\tпоэтому изменение у Пети не влияет на Васю.\n";
            Student andrey("Андрей", vasya.get_grades());
            std::cout << "\n\t4. Создан студент Андрей (независимая копия оценок Васи):\n";
            andrey.print();
            std::cout << "\n\tТеперь изменим оценки Васи (введи новые оценки, >=2 и <=5):\n";
            std::cout << "\tКоличество оценок (должно быть >= " << vasya.get_grades().size() << "):\n";
            int n = get_pos();
            std::vector<int> new_grades(n);
            for (int i = 0; i < n; ++i) {
                new_grades[i] = get_grade("\tОценка " + std::to_string(i + 1) + ": ");
            }
            vasya.set_grades(new_grades);
            std::cout << "\n\tПосле изменения оценок Васи:\n";
            std::cout << ""; vasya.print();
            std::cout << ""; andrey.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "\n\t~~ Демонстрация класса Студент ~~\n";
            std::cout << "\n\t1. Создаём Студента 1 (конструтор по умолчанию)";
            Student s1;
            std::cout << "\n\tРезультатик: ";
            s1.print();
            std::cout << "\n\t2. Введи имя студента: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string name;
            std::getline(std::cin, name);
            std::cout << "\tВведи количество оценок: \n";
            int n = get_pos();
            std::vector<int> grades(n);
            for (int i = 0; i < n; ++i) {
                grades[i] = get_grade("\tОценка " + std::to_string(i + 1) + ": ");
            }
            Student s2(name, grades);
            std::cout << "\n\tСоздаём Стеднта 2";
            std::cout << "\n\tРезультатик: ";
            s2.print();
            std::cout << "\n\t3. Создаём Студента 3 (копия СТудента 2)";
            Student s3 = s2;
            std::cout << "\n\tРезультатик: ";
            s3.print();
            std::cout << "\n\t4. Создаём пустого студента 4, присваиваем ему Студента 3";
            Student s4;
            std::cout << "\n\tДо присваивания: ";
            s4.print();
            s4 = s3;
            std::cout << "\tПосле присваивания: ";
            s4.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 3: break;
        default:
            std::cout << "\n\tОшибочка( выбери 1, 2 или 3!\n";
            std::cin.get();
            std::cin.get();
        }
        if (sub_choice != 3) {
            system("cls");
        }
    } while (sub_choice != 3);
}
void menu_task4() {
    int sub_choice;
    do {
        std::cout << "\n\t~~ Задание 4 – Точка и Линия ~~\n\n";
        std::cout << "\t1. Решение задачи\n";
        std::cout << "\t2. Демонстрация класса\n";
        std::cout << "\t3. Назад в главное меню\n";
        sub_choice = get_int("\n\tВыбери: ", 1, 3);
        system("cls");
        switch (sub_choice) {
        case 1: {
            std::cout << "\n\t~~ Решение задачи 4 ~~\n";
            std::cout << "\n\tСоздаём три точки:\n";
            Point4 p1(3, 5);
            Point4 p2(25, 6);
            Point4 p3(7, 8);
            p1.print();
            p2.print();
            p3.print();
            std::cout << "\n\tСоздаём три линии:\n";
            Line4 line1(Point4(1, 3), Point4(23, 8));
            Line4 line2(5, 10, 25, 10);
            Line4 line3(line1.get_start(), line2.get_end());
            std::cout << "\tЛиния 1: "; line1.print();
            std::cout << "\tЛиния 2: "; line2.print();
            std::cout << "\tЛиния 3: "; line3.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "\n\t~~ Демонстрация классов Точки и Линии ~~\n";
            double x = get_double("\n\tВведи X для точки: ");
            double y = get_double("\tВведи Y для точки: ");
            Point4 pt(x, y);
            std::cout << "\n\tСоздана точка: "; pt.print();
            std::cout << "\n\t1. Через две точки:\n";
            double x1 = get_double("\tX1: "), y1 = get_double("\tY1: ");
            double x2 = get_double("\tX2: "), y2 = get_double("\tY2: ");
            Line4 l1(Point4(x1, y1), Point4(x2, y2));
            std::cout << "\tЛиния: "; l1.print();
            std::cout << "\n\t2. Через 4 числа:\n";
            x1 = get_double("\tX начала: "); y1 = get_double("\tY начала: ");
            x2 = get_double("\tX конца: "); y2 = get_double("\tY конца: ");
            Line4 l2(x1, y1, x2, y2);
            std::cout << "\tЛиния: "; l2.print();
            std::cin.get();
            std::cin.get();
            break;
        }
        case 3: break;
        default:
            std::cout << "\n\tОшибочка( выбери 1, 2 или 3!\n";
            std::cin.get();
            std::cin.get();
        }
        if (sub_choice != 3) {
            system("cls");
        }
    } while (sub_choice != 3);
}
void menu_task5() {
    int sub_choice;
    do {
        std::cout << "\n\t~~ Задание 5 – Длина Линии ~~\n\n";
        std::cout << "\t1. Решение задачи\n";
        std::cout << "\t2. Демонстрация метода расчета длины\n";
        std::cout << "\t3. Назад в главное меню\n";
        sub_choice = get_int("\n\tВыбери: ", 1, 3);
        system("cls");
        switch (sub_choice) {
        case 1: {
            std::cout << "\n\t~~ Решение задачи 5 ~~\n";
            std::cout << "\n\tСоздаём линию от {1;1} до {10;15}...\n";
            Line4 line(Point4(1, 1), Point4(10, 15));
            std::cout << "\tЛиния: "; line.print();
            std::cout << "\n\tДлина: " << line.get_length() << "\n";
            std::cin.get();
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "\n\t~~ Демонстрация метода расчета длины ~~\n";
            double x1 = get_double("\n\tВведи X начала: ");
            double y1 = get_double("\tВведи Y начала: ");
            double x2 = get_double("\tВведи X конца: ");
            double y2 = get_double("\tВведи Y конца: ");
            Line4 line(x1, y1, x2, y2);
            std::cout << "\n\tСоздана линия:\n";
            std::cout << ""; line.print();
            std::cout << "\n\tДлина: " << line.get_length() << "\n";
            std::cin.get();
            std::cin.get();
            break;
        }
        case 3: break;
        default:
            std::cout << "\n\tОшибочка( выбери 1, 2 или 3!\n";
            std::cin.get();
            std::cin.get();
        }
        if (sub_choice != 3) {
            system("cls");
        }
    } while (sub_choice != 3);
}