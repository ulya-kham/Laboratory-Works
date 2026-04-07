#pragma once
#include <iostream>
#include <string>
class Point4 {//класс точка - с обновлениями
private:
    double x;//коорд X
    double y;//коорд Y
public:
    Point4(double x_val, double y_val);//с парам (единственный)
    Point4(const Point4& other);//копир
    ~Point4();//дестр
    Point4& operator=(const Point4& other);//присваив
    double get_x() const { return x; }//геттер X
    double get_y() const { return y; }//геттер Y
    void set_x(double x_val) { x = x_val; }//сеттер X
    void set_y(double y_val) { y = y_val; }//сеттер Y
    std::string to_string() const;//текст предст
    void print() const;//вывод
};
class Line4 {//класс Линия с обновлением
private:
    Point4 start;//начало
    Point4 end;//конец
public:
    Line4(const Point4& start_point, const Point4& end_point);//через две точки
    Line4(double x1, double y1, double x2, double y2);//через 4 числа
    Line4(const Line4& other);//копир
    ~Line4();//дестр
    Line4& operator=(const Line4& other);//присваив
    Point4 get_start() const { return start; }//геттер начала
    Point4 get_end() const { return end; }//геттер конца
    void set_start(const Point4& p) { start = p; }//сеттер начала
    void set_end(const Point4& p) { end = p; }//сеттер конца
    std::string to_string() const;//текст предст
    void print() const;//вывод
    int get_length() const;//длина (целое число)
};