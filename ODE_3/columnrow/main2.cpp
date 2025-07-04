#include <iostream>
#include <filesystem>
#include <Eigen/Dense>
#include "BC_Solver.hpp"
#include "Jacobi.hpp"
#undef USE_JACOBI
#define USE_JACOBI

int main() {
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_3/Jacobi/data"; //データ出力フォルダーのパスを指定
#ifdef USE_JACOBI
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_3/columnrow/data"; //データ出力フォルダーのパスを指定
    BC_Solver fold(Mypath);                      //2階常微分方程式ソルバーインスタンス
    fold.C=200;                                  //C=1に設定. XminやXmaxも設定できるけどデフォルトの値でも良い
    fold.N=40;                                  //100分割
    fold.solve();                        //解いて, N100C1.data というファイルに出力
    fold.Save("data2.dat");                        //解いて, N100C1.data というファイルに出力

#else

int main() {
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_3/columnrow/data"; //データ出力フォルダーのパスを指定
    BC_Solver fold(Mypath);                      //2階常微分方程式ソルバーインスタンス
    fold.C=1.0;                                  //C=1に設定. XminやXmaxも設定できるけどデフォルトの値でも良い
    fold.N=100;                                  //100分割
    fold.solve();                        //解いて, N100C1.data というファイルに出力
    fold.Save("data.dat");                        //解いて, N100C1.data というファイルに出力
}

#endif
    return 0;
}

