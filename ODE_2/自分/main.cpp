#include <iostream>
#include "ode_euler.hpp"
#include <cmath> // exp関数を使用するために必要

int main() {
    // Create an instance of the ODEProblem class
    ODE_euler solver,solver2(1.0,0.0,0.0);
    solver2.xmax = 2* M_PI; // 2π
    solver2.c = 1.0;
    //solver2.dx = solver.xmax / 100; // ステップサイズを0.01に設定
    //int n_max=1.0/solver.dx;
    //for(int i=0;i<n_max;i++){
    //    solver2.step(); //１ステップ進める
    //}
    solver2.initiakize(); //初期化
    solver2.solve(); //ODEを解く
    solver2.print(); //結果を表示
    return 0;
}

