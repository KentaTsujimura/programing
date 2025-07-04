#include "TridiagonalSolver.hpp"

TridiagonalSolver::TridiagonalSolver(int N, double L, std::filesystem::path path) : N(N), L(L), datafolder(path) {
    h = L / (N + 1);
    a.resize(N - 1, 1.0 / (h * h));
    b.resize(N, -2.0 / (h * h));
    c.resize(N - 1, 1.0 / (h * h));
    rhs.resize(N, 0.0);
}

void TridiagonalSolver::savedata(const std::vector<double>& y, const std::string& filename) {
    std::ofstream ofs(datafolder / filename);
    if (!ofs) {
        std::cerr << "ファイルを開けません: " << (datafolder / filename) << std::endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        double x = (i + 1) * (L / (N + 1));
        ofs << x << " " << y[i] << std::endl;
    }
}

void TridiagonalSolver::setupEquation() {
    for (int i = 0; i < N; ++i) {
        b[i] += 1.0;
    }
}

void TridiagonalSolver::setBoundary(double A, double B) {
    rhs[0]   -= a[0] * A;
    rhs[N-1] -= c[N-2] * B;
}

std::vector<double> TridiagonalSolver::solve() {
    std::vector<double> cp = c;
    std::vector<double> bp = b;
    std::vector<double> dp = rhs;

    for (int i = 1; i < N; ++i) {
        double m = a[i-1] / bp[i-1];
        bp[i] -= m * cp[i-1];
        dp[i] -= m * dp[i-1];
    }

    std::vector<double> y(N);
    y[N-1] = dp[N-1] / bp[N-1];
    for (int i = N-2; i >= 0; --i) {
        y[i] = (dp[i] - cp[i] * y[i+1]) / bp[i];
    }
    return y;
}