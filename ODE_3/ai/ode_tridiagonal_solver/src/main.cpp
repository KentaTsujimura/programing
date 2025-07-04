#include <iostream>
#include <cmath>
#include "tridiagonal_solver.hpp"

int main() {
    int n = 10; // 行列のサイズ
    double y0 = 0.0; // 左端の境界条件
    double yn = 1.0; // 右端の境界条件

    TridiagonalSolver solver(n);
    solver.setBoundaryConditions(y0, yn);
    solver.solve();

    std::vector<double> solution = solver.getSolution();

    std::cout << "Solution:" << std::endl;
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "y(" << i * (2 * M_PI / n) << ") = " << solution[i] << std::endl;
    }

    return 0;
}