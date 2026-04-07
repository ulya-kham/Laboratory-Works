#include "task2.h"
#include <iostream>
Line::Line() : start(Point(0, 0)), end(Point(0, 0)) {}//по умолч
Line::Line(const Point& start_point, const Point& end_point)//с парам
    : start(start_point), end(end_point) {
}
Line::Line(const Line& other) : start(other.start), end(other.end) {}//копир
Line::~Line() {}//дестр
Line& Line::operator=(const Line& other) {//присваив
    if (this != &other) {
        start = other.start;
        end = other.end;
    }
    return *this;
}
std::string Line::to_string() const {//текст предст
    return "от " + start.to_string() + " до " + end.to_string();
}
void Line::print() const {//вывод
    std::cout << "" << to_string() << "\n";
}