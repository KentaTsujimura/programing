#pragma once
#include <vector>

class TridiagonalSolver {
public:
    TridiagonalSolver(int n);
    void setBoundaryConditions(double y0, double yn);
    void solve();
    std::vector<double> getSolution();

private:
    int n; // Size of the matrix
    double y0; // Boundary condition at the start
    double yn; // Boundary condition at the end
    std::vector<double> solution; // Solution vector
    std::vector<double> a; // Lower diagonal
    std::vector<double> b; // Main diagonal
    std::vector<double> c; // Upper diagonal
    std::vector<double> d; // Upper diagonal
};