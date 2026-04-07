#include "task4.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
Point4::Point4(double x_val, double y_val) : x(x_val), y(y_val) {}//с парам
Point4::Point4(const Point4& other) : x(other.x), y(other.y) {}//копир
Point4::~Point4() {}//дестр
Point4& Point4::operator=(const Point4& other) {//присваив
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}
std::string Point4::to_string() const {//текст предст
    std::ostringstream oss;
    if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
        oss << "{" << static_cast<int>(x) << "; " << static_cast<int>(y) << "}";
    }
    else {
        oss << std::fixed << std::setprecision(3) << "{" << x << "; " << y << "}";
    }
    return oss.str();
}
void Point4::print() const {//вывод
    std::cout << "\t" << to_string() << "\n";
}

Line4::Line4(const Point4& start_point, const Point4& end_point)//через две точки
    : start(start_point), end(end_point) {
}
Line4::Line4(double x1, double y1, double x2, double y2)//через 4 числа
    : start(Point4(x1, y1)), end(Point4(x2, y2)) {
}
Line4::Line4(const Line4& other) : start(other.start), end(other.end) {}//копир
Line4::~Line4() {}//дестр
Line4& Line4::operator=(const Line4& other) {//присваив
    if (this != &other) {
        start = other.start;
        end = other.end;
    }
    return *this;
}
std::string Line4::to_string() const {//текст предст
    return "Линия от " + start.to_string() + " до " + end.to_string();
}
void Line4::print() const {//вывод
    std::cout << "\t" << to_string() << "\n";
}
int Line4::get_length() const {//длина с округл
    double dx = end.get_x() - start.get_x();
    double dy = end.get_y() - start.get_y();
    double distance = std::sqrt(dx * dx + dy * dy);
    return static_cast<int>(std::round(distance));
}