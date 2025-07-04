#pragma once
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cmath>
#include <Eigen/Dense>

class Jacobi {
    private:
    Eigen::MatrixXd myMAT;
    Eigen::VectorXd myVEC;

    public:
    double C;
    int N = 100;
    double Xmin = 0.0;
    double Xmax = 1.0;
    double Y0 = 0.0;      // 左端の境界条件
    double Y1 = 1.0;      // 右端の境界条件
    double dx;
    std::vector<double> mySOL; // 解を格納するベクトル

    Jacobi(){std::cout << "this' Jacobi" << std::endl;} 

    void resize(size_t N){
    myMAT.resize(N-1,N-1);
    myMAT.setZero();
    myVEC.resize(N-1);
    myVEC.setZero();
    mySOL.resize(N-1);
    }

    void solve (int max_iter = 10000) {
    size_t message_iter = 1000; // 途中で「XX回やったよ〜」とメッセージを出したい
    int n = myMAT.rows();
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd x_new = Eigen::VectorXd::Zero(n);
    double tol = 1e-8;
    size_t iter = 0;
    double err = 1.0;

    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) sigma += myMAT(i, j) * x[j];
            }
            x_new[i] = (myVEC[i] - sigma) / myMAT(i, i);
        }
        if (err = (x_new - x).norm() < tol) break;
        x = x_new;
        }

        // 結果をmySOLに格納
        if (!(iter%message_iter)){
                std::cout << "Iteration " << iter << ": Error = " << err << std::endl;
        }

        if (iter == max_iter)
            std::cout << "Timeout. Error= " << err << std::endl;
        else
            std::cout << "Converged in " << iter << " iterations." << std::endl;
        for (int i = 0; i < myMAT.rows(); ++i)
            mySOL[i + 1] = x_new[i];
}

    void Init(){
        dx = (Xmax - Xmin) / (myVEC.size() + 1); // 区間幅を計算

        for(int i=0; i< myMAT.rows(); ++i){
            myMAT(i,i) = 2.0 - C * dx * dx; // 対角成分を更新
            if(i > 0) {
                myMAT(i,i-1) = -1.0; // 左隣の成分
            }
            if(i < myMAT.rows() - 1) {
                myMAT(i,i+1) = -1.0; // 右隣の成分
            }
        }

        myVEC[0] = Y0; // 左端の境界条件
        myVEC[myVEC.size()-1] = Y1; // 右端の境界条件
        mySOL[0] = Y0; // 左端の境界条件
        mySOL[mySOL.size()-1]=Y1;   // 右端の境界条件
    }

    void Inv(){
        auto SOL=myMAT.inverse()*myVEC;
        mySOL[0]=Y0; //これは境界条件
        for(int i=0;i<SOL.size(); ++i) mySOL[i+1]=SOL[i];
        mySOL[mySOL.size()-1]=Y1;
    }

};
