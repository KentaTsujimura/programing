#pragma once
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cmath>
class TridiagonalSolver {
public:

    TridiagonalSolver(int N, double L,std::filesystem::path path);
    void setupEquation();
    void setBoundary(double A, double B);
    void savedata(const std::vector<double>& y, const std::string& filename);
    std::vector<double> solve();

private:
    int N;
    double L, h;
    std::vector<double> a, b, c, rhs;
    std::filesystem::path datafolder;
};