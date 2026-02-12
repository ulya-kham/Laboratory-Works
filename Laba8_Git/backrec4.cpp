#include "backrec4.h"
#include <iostream>
#include <fstream>
#include <limits>
#ifdef max
#undef max//избавились от макроса Винды
#endif
void backtrack(const std::vector<Art>& arts, int idx, int min_w, int max_w, //рекурсия с возвратом. Берем или не берем
    std::vector<bool>& cur_sel, int cur_w, int cur_v,
    std::vector<bool>& best_sel, int& best_vol, bool& sol_found) {
    if (idx == static_cast<int>(arts.size())) {//все рассмотрели
        if (cur_w >= min_w && cur_w <= max_w) {//проверили диапазон
            if (cur_v < best_vol) {//запоминаем лучшее 
                best_vol = cur_v;
                best_sel = cur_sel;
                sol_found = true;
            }
        }
        return;
    }
    backtrack(arts, idx + 1, min_w, max_w, cur_sel, cur_w, cur_v, best_sel, best_vol, sol_found);//не берем и идем дальше
    cur_w += arts[idx].w;//берем текуий и все добавляем
    cur_v += arts[idx].v;
    cur_sel[idx] = true;
    if (cur_w <= max_w) {//если не превысил - продолжаем
        backtrack(arts, idx + 1, min_w, max_w, cur_sel, cur_w, cur_v, best_sel, best_vol, sol_found);
    }
    cur_sel[idx] = false;//делаем откат перед рассмотром других
}
bool read_data(const std::string& fname, std::vector<Art>& arts, int& min_w, int& max_w) {//чтение файла
    std::ifstream f(fname);
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть файлик \"" << fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return false;
    }
    int n;
    if (!(f >> n >> min_w >> max_w)) {
        std::cout << "\n\tОшибочка( некорректный формат данных в первой строке файлика\n";
        f.close();
        return false;
    }
    if (n <= 0) {
        std::cout << "\n\tОшибочка( количество артефактов должно быть положительным (" << n << ")\n";
        f.close();
        return false;
    }
    if (min_w < 0 || max_w < min_w) {
        std::cout << "\n\tОшибочка( некорректные границы веса (A=" << min_w << ", B=" << max_w << ")\n";
        f.close();
        return false;
    }
    std::vector<int> ws(n);
    for (int i = 0; i < n; i++) {
        if (!(f >> ws[i])) {
            std::cout << "\n\tОшибочка( не хватает данных о весах (ожидалось " << n << " чисел)\n";
            f.close();
            return false;
        }
        if (ws[i] < 0) {
            std::cout << "\n\tОшибочка( вес артефакта №" << (i + 1) << " отрицательный (" << ws[i] << ")\n";
            f.close();
            return false;
        }
    }
    std::vector<int> vs(n);
    for (int i = 0; i < n; i++) {
        if (!(f >> vs[i])) {
            std::cout << "\n\tОшибочка( не хватает данных об объемах (ожидалось " << n << " чисел)\n";
            f.close();
            return false;
        }
        if (vs[i] < 0) {
            std::cout << "\n\tОшибочка( объем артефакта №" << (i + 1) << " отрицательный (" << vs[i] << ")\n";
            f.close();
            return false;
        }
    }
    f.close();
    arts.clear();//делаем список
    for (int i = 0; i < n; i++) {
        Art a;
        a.w = ws[i];
        a.v = vs[i];
        a.idx = i + 1;
        arts.push_back(a);
    }
    return true;
}
void find_optimal(const std::vector<Art>& arts, int min_w, int max_w, std::vector<bool>& best_sel, int& best_vol) {//оптимальное решение
    std::vector<bool> cur_sel(arts.size(), false);//текущий - пустой
    best_sel.assign(arts.size(), false);//лучший набор
    best_vol = std::numeric_limits<int>::max();//лучший об
    bool sol_found = false;
    backtrack(arts, 0, min_w, max_w, cur_sel, 0, 0, best_sel, best_vol, sol_found);//запускаем с первого
    if (!sol_found) {
        best_vol = -1;
    }
}
void print_result(const std::vector<Art>& arts, const std::vector<bool>& best_sel, int best_vol, int min_w, int max_w) {//вывод
    if (best_vol == -1) {
        std::cout << "\n\tКошмар! Решение не найдено... нельзя подобрать артефакты с весом в диапазоне [" << min_w << ", " << max_w << "] кг\n";
        return;
    }
    std::cout << "\n\t~~ Результатик: ~~\n\n";
    std::cout << "\tВыбранные артефакты (их порядковые номера): ";
    bool first = true;
    for (size_t i = 0; i < best_sel.size(); i++) {
        if (best_sel[i]) {
            if (!first) std::cout << ", ";
            std::cout << arts[i].idx;
            first = false;
        }
    }
    std::cout << "\n";
    int total_w = 0;//пересчитываем
    int total_v = 0;
    for (size_t i = 0; i < best_sel.size(); i++) {
        if (best_sel[i]) {
            total_w += arts[i].w;
            total_v += arts[i].v;
        }
    }
    std::cout << "\tСуммарный вес: " << total_w << " кг\n";
    std::cout << "\tСуммарный объем: " << total_v << " куб.см\n";
}