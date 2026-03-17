#pragma once
#include <vector>
#include <string>
int get_int(const std::string& prompt = "");//проверка на целые знач
int get_n3();//делимость 3
int get_chetn();//четность
void fill_vector(std::vector<int>& vec, int method, int n = 0);//заполнения векторов
int get_pos();//положительное
void read_file_vec(const std::string& filename, std::vector<int>& vec);//чтение и запись в вектор файла