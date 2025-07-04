#include <iostream>
#include <filesystem>
#include "TridiagonalSolver.hpp"

int main() {
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_3/ture/data";

    int N = 100;
    double L = 10.0;
    double A = 0.0, B = 0.0; // y(0)=0, y(L)=0

    TridiagonalSolver solver(N, L, Mypath);
    solver.setupEquation();
    solver.setBoundary(A, B);
    std::vector<double> y = solver.solve();
    solver.savedata(y, "result.dat");

    for (int i = 0; i < N; ++i) {
        double x = (i + 1) * (L / (N + 1));
        std::cout << x << " " << y[i] << std::endl;
    }
    return 0;
}