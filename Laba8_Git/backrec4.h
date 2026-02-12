#pragma once
#include <vector>
#include <string>
struct Art {
    int w;
    int v;
    int idx;
};
bool read_data(const std::string& fname, std::vector<Art>& arts, int& min_w, int& max_w);//чтение из файла
//решение(поиск подмножества перебором)
void find_optimal(const std::vector<Art>& arts, int min_w, int max_w,std::vector<bool>& best_sel, int& best_vol);
void print_result(const std::vector<Art>& arts, const std::vector<bool>& best_sel,int best_vol, int min_w, int max_w); //вывод рез-та