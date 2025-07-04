#include "tridiagonal_solver.hpp"
#include <iostream>
#include <vector>

TridiagonalSolver::TridiagonalSolver(int n) : n(n), a(n-1), b(n), c(n-1), d(n), solution(n) {
    // Initialize the coefficients of the tridiagonal matrix
    for (int i = 0; i < n - 1; ++i) {
        a[i] = -0.5; // Lower diagonal
        c[i] = -0.5; // Upper diagonal
    }
    for (int i = 0; i < n; ++i) {
        b[i] = 1.0; // Main diagonal
    }
}

void TridiagonalSolver::setBoundaryConditions(double y0, double yn) {
    d[0] = y0; // Boundary condition at the start
    d[n - 1] = yn; // Boundary condition at the end
}

void TridiagonalSolver::solve() {
    // Forward elimination
    for (int i = 1; i < n; ++i) {
        double m = a[i - 1] / b[i - 1];
        b[i] -= m * c[i - 1];
        d[i] -= m * d[i - 1];
    }

    // Back substitution
    solution[n - 1] = d[n - 1] / b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        solution[i] = (d[i] - c[i] * solution[i + 1]) / b[i];
    }
}

std::vector<double> TridiagonalSolver::getSolution() {
    return solution;
}