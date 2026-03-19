#pragma once
#include <vector>
#include <string>
int get_int(const std::string& prompt = "");//проверка на целые знач
int get_n3();//делимость 3
int get_chetn();//четность
void fill_vector(std::vector<int>& vec, int method, int n = 0);//заполнения векторов
int get_pos();//положительное
void read_file_vec(std::vector<int>& vec);//чтение из файлва
int get_min10(); //возвращает n >= 10
int get_nechet_min3();  // нечётное n >= 3
int get_min2();  // n >= 2