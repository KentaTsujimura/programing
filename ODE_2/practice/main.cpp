#include <iostream>
#include <filesystem>
#include "ic_solvar.hpp"


int main() {
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_2/practice/data"; //データ出力フォルダーのパスを指定
    ic_solvar ode(Mypath);                      //2階常微分方程式ソルバーインスタンス
    ode.c=1.0;                                  //C=1に設定. XminやXmaxも設定できるけどデフォルトの値でも良い
    ode.N=100;                                  //100分割
    ode.Solve("C1N100.dat");                        //解いて, N100C1.data というファイルに出力
    ode.N=10;                                  //10分割
    ode.Solve("C1N10.dat");                        //解いて, N10C1.data というファイルに出力
    ode.N=5;                                  //5分割
    ode.Solve("C1N5.dat");                        //解いて, N5C1.data というファイルに出力
    ode.N=3;                                  //3分割
    ode.Solve("C1N3.dat");                        //解いて, N3C1.data というファイルに出力
    return 0;
}

