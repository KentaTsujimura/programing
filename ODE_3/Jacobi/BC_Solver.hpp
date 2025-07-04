#pragma once
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cmath>

class BC_Solver {
public:
    double C=1.0;
    int N = 100;
    double Xmin = 0.0;
    double Xmax = 1.0;
    double Y0 = 0.0;      // 左端の境界条件
    double Y1 = 1.0;      // 右端の境界条件
    std::vector<double> y; // y座標のベクトル
    std::vector<double> b;
    std::filesystem::path datafile; // データ出力ファイル名
    std::filesystem::path datafolder; // データ出力フォルダーのパス
    double dx;

    BC_Solver(std::filesystem::path path) : datafolder(path)
    {
        if (!std::filesystem::exists(path)) std::filesystem::create_directories(path);
        //datafile = path / "data.dat";               //データ出力ファイル名
        std::cout << "IC_Solver::Using DataFolder[" << path.string() << "]" << std::endl;
    }

    void solve() {
        dx = (Xmax - Xmin) / N; // 区間幅を計算
        b.resize(N - 1); // y座標のベクトルを初期化
        y.resize(N + 1); // y座標のベクトルを初期化境界条件の二つを追加
        y[0] = Y0; // 左端の境界条件
        y[N] = Y1; // 右端の境界条件

        class ROW {
        public:
            double L,C,R;           // 左列,中列,右列
        };
        std::vector<ROW> A(N-1);    //要素数を最初から定義しても良い クラスrowを使っtて三重配列を定義
        for(auto& row:A) {  row.L=-1.;   row.C=2.-C*dx*dx;  row.R=-1.;}
        // 境界条件
        for(auto& v:b) v=0;
        b[0] = Y0;
        b[N-2] = Y1;
        
        //前進消去
        for(int i=1;i<N-1;++i) {
            auto m=A[i].L/A[i-1].C;
            A[i].C -= m * A[i-1].R;
            b[i]   -= m * b[i-1];
        }
        y[N]=Y1;
        //後退代入
        for(int i=N-1; i>0; --i){
        y[i]=(b[i-1]-((i<N-1)? A[i-1].R*y[i+1] : 0.0 ))/A[i-1].C;
        }
}

void Save(std::filesystem::path filename){
    datafile = datafolder / filename; //データ出力ファイル名
    std::cout << "IC_Solver::Using DataFile[" << datafile.string() << "]" << std::endl;

    std::ofstream ofs(datafile);
    for(int i=0; i<= N; ++i) ofs << i*dx << " " << y[i] << std::endl;
    ofs.close();
}

};
