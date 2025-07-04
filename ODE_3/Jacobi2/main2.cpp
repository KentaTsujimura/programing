#include <iostream>
#include <filesystem>
#include <Eigen/Dense>
#include "BC_Solver.hpp"
#include "Jacobi.hpp"
//#undef USE_JACOBI
#define USE_JACOBI

int main() {
    std::filesystem::path Mypath = getenv("HOME");
    Mypath /= "Documents/programing/ODE_3/Jacobi/data"; //データ出力フォルダーのパスを指定
#ifdef USE_JACOBI
    Jacobi JJ;                        //2階常微分方程式ソルバーインスタンス
    JJ.C=0.2;                                  //C=1に設定. XminやXmaxも設定できるけどデフォルトの値でも良い
    JJ.resize(200);                                  //100分割
    JJ.Init();
    JJ.filename = Mypath/"C02_N200.data"; //出力ファイル名を指定
    JJ.SaveTimes.insert(10000);     //1000回目に保存
    JJ.SaveTimes.insert(20000);     //2000回目に保存
    if (!JJ.solve(100000)) std::cout << "ERROR!! OOPS!! DID NOT CONVERGE FUCK" << std::endl;
    JJ.Save(Mypath/"C02_N200.jac");
    JJ.Inv();        //逆行列で
    JJ.Save(Mypath/"C02_N200.sol");     //こっちが正解
     

#else

    BC_Solver fold(Mypath);                      //2階常微分方程式ソルバーインスタンス
    fold.C=1.0;                                  //C=1に設定. XminやXmaxも設定できるけどデフォルトの値でも良い
    fold.N=100;                                  //100分割
    fold.solve();                        //解いて, N100C1.data というファイルに出力
    fold.Save("data.dat");                        //解いて, N100C1.data というファイルに出力

#endif

    return 0;
}

// お試しコミット

// お試しコミット

// お試しコミット

//これも

//　これもこれもこれもこれもs