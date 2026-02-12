#pragma once
#include <string>

bool read_params(const std::string& fname, int& k, int& n);
double count_valid_numbers(int k, int n);
bool write_result(const std::string& fname, double result); 
