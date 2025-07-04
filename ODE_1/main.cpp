#include <iostream>
#include "ode_euler.hpp"

int main() {
    // Create an instance of the ODEProblem class
    ODE_euler solver,solver2(1.0,0.0);
    solver2.dx =0.02;
    int n_max=1.0/solver.dx;
    //for(int i=0;i<n_max;i++){
    //    solver2.step(); //１ステップ進める
    //}
    solver2.solve(); //ODEを解く
    solver2.print(); //結果を表示
    return 0;
}

