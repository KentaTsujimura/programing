#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cmath>

class ic_solvar {
    double xmax=2*M_PI; // 2π
    double xmin=0.0;
    double y0;
    double z0;

    std::filesystem ::path datafile;
    std::filesystem ::path datafolder;

public:         //外から操作可能
    int N;
    double c; //C=1に設定

    ic_solvar(std::filesystem::path path) : z0(0.0),y0(1.0),datafolder(path) 
    {
        if (!std::filesystem::exists(path)) std::filesystem::create_directories(path);
        //datafile = path / "data.dat";               //データ出力ファイル名
        std::cout << "IC_Solver::Using DataFolder[" << path.string() << "]" << std::endl;
    }
    ic_solvar() {
        std::cout << "フォルダー指定されてないですよ" << std::endl;
    }

    void Solve(std::string filename) {
        datafile = datafolder / filename; //データ出力ファイル名

        std::cout << "IC_Solver::Using DataFile[" << datafile.string() << "]" << std::endl;

        std::ofstream ofs(datafile);      //出力ファイルを書き出し用に準備

        double dx=xmax/N;     //区間幅はこうなる
        double y=y0,z=z0; //初期値を設定
        for(int i=0;i<N;i++)
            {     
                y=y+z*dx;
                z=z-c*y*dx;
                ofs << dx*(i+1) << " " << y << std::endl;
            }   
            
        ofs.close();//出力ファイルをディスクに書き込む

    }

};