#pragma once
#include <iostream>
#include <vector>
#include <string>
class Student {
private:
    std::string name;//имя
    std::vector<int> grades;//оценки
public:
    Student();//констр по умолч
    Student(const std::string& student_name, const std::vector<int>& student_grades);//с парам
    Student(const Student& other);//копир
    ~Student();//дестр
    Student& operator=(const Student& other);//присваив
    std::string get_name() const { return name; }//геттер имени
    std::vector<int> get_grades() const { return grades; }//геттер оценок
    void set_name(const std::string& new_name) { name = new_name; }//сеттер имени
    void set_grades(const std::vector<int>& new_grades) { grades = new_grades; }//сеттер оценок
    std::string to_string() const;//текст предст
    void print() const;//вывод
};