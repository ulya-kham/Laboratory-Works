#include "homedyn1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
bool read_board(const std::string& fname, std::vector<std::vector<int>>& board, int& n) {//читаем
    std::ifstream f(fname);
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось открыть файлик \"" << fname << "\"\n";
        std::cout << "\tПроверька имя файлика и его расположение :)\n";
        return false;
    }
    if (!(f >> n)) {
        std::cout << "\n\tОшибочка( не удалось прочитать размер доски N\n";
        f.close();
        return false;
    }
    if (n <= 1 || n >= 80) {
        std::cout << "\n\tОшибочка( размер доски должен быть от 2 до 79 (а у тебя N=" << n << ")\n";
        f.close();
        return false;
    }
    board.resize(n, std::vector<int>(n));//слздаем досочку
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(f >> board[i][j])) {
                std::cout << "\n\tОшибочка( не хватает данных в файлике (ожидалось " << n * n << " чисел)\n";
                f.close();
                return false;
            }
            if (board[i][j] < 0 || board[i][j] > 100) {
                std::cout << "\n\tОшибочка( число в клетке [" << i << "][" << j << "] вне диапазона 0..100 (" << board[i][j] << ")\n";
                f.close();
                return false;
            }
        }
    }
    f.close();
    return true;
}
int find_max_sum(const std::vector<std::vector<int>>& board, int n) {//поиск макс суммы
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));//создали двумерный массив
    dp[0][n - 1] = board[0][n - 1];//встали на правй верхний угол
    for (int i = 0; i < n; i++) {//сверху вниз
        for (int j = n - 1; j >= 0; j--) {//справа на лево
            if (i == 0 && j == n - 1) continue;//это стартовая - пропуск
            int from_top = (i > 0) ? dp[i - 1][j] : -1;
            int from_right = (j < n - 1) ? dp[i][j + 1] : -1;
            dp[i][j] = board[i][j] + std::max(from_top, from_right);//выбор большей суммы
        }
    }
    return dp[n - 1][0];//до левого угла
}
bool write_result(const std::string& fname, int result) {//выписываем результат
    std::ofstream f(fname);
    if (!f.is_open()) {
        std::cout << "\n\tОшибочка( не удалось создать выходной файлик \"" << fname << "\"\n";
        return false;
    }
    f << result;
    f.close();
    std::cout << "\n\tУра! Результат записан в файлик \"" << fname << "\"\n";
    return true;
}