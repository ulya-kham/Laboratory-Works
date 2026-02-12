#pragma once
#include <vector>
#include <string>

bool read_board(const std::string& fname, std::vector<std::vector<int>>& board, int& n);
int find_max_sum(const std::vector<std::vector<int>>& board, int n);
bool write_result(const std::string& fname, int result);