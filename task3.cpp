#include "task3.h"
#include <iostream>
Student::Student() : name("Мистер Х"), grades({}) {}//по умолч
Student::Student(const std::string& student_name, const std::vector<int>& student_grades)//с парам
    : name(student_name), grades(student_grades) {
}
Student::Student(const Student& other) : name(other.name), grades(other.grades) {}//копир
Student::~Student() {}//дестр
Student& Student::operator=(const Student& other) {//присваив
    if (this != &other) {
        name = other.name;
        grades = other.grades;
    }
    return *this;
}
std::string Student::to_string() const {//текст предст
    std::string result = "Имя: " + name + " [";
    for (size_t i = 0; i < grades.size(); ++i) {
        if (i > 0) result += ", ";
        result += std::to_string(grades[i]);
    }
    result += "]";
    return result;
}
void Student::print() const {//вывод
    std::cout << "\t" << to_string() << "\n";
}