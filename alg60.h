#pragma once
#include <functional>
#include <numeric>
struct AvgFunctor {//функтор для ср.ар
    double operator()(int a, int b) const { //среднее соседей
        return (static_cast<double>(a) + b) / 2.0;
    }
};
void task4();//задание 60