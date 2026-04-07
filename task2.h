#pragma once
#include "task1.h"
#include <iostream>
class Line {
private:
    Point start;//начало
    Point end;//конец
public:
    Line();//констрпо умолч
    Line(const Point& start_point, const Point& end_point);//с парам
    Line(const Line& other);//копир
    ~Line();//дестр
    Line& operator=(const Line& other);//присваив
    Point get_start() const { return start; }//геттер начала
    Point get_end() const { return end; }//геттер конца
    void set_start(const Point& p) { start = p; }//сеттер начала
    void set_end(const Point& p) { end = p; }//сеттер конца
    std::string to_string() const;//текст предст
    void print() const;//вывод
};