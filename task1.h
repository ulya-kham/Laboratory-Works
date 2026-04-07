#pragma once
#include <iostream>
#include <string>
class Point {
private:
    double x;//коорд х
    double y;//коорд у
public:
    Point();//констр по умолч
    Point(double x_val, double y_val);//с парам
    Point(const Point& other);//копир
    ~Point();//дестр
    Point& operator=(const Point& other);//присваив
    double get_x() const { return x; }//геттер X
    double get_y() const { return y; }//геттер Y
    void set_x(double x_val) { x = x_val; }//сеттер X
    void set_y(double y_val) { y = y_val; }//сеттер Y
    const Point& get_ref() const { return *this; }//ссылка для слежки
    std::string to_string() const;//текст предст
    void print() const;//вывод
};