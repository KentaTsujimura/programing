#pragma once
#include <iostream>
#include <vector>

class ODE_euler {
    double y;   //private 外から操作不可
    double x;
public:         //外から操作可能
    double dx;

    ODE_euler(){
        std::cout << "Starting Solvar-A" << std::endl;
    }
    ODE_euler(double y0, double x0):y(y0),x(x0) 
    {
        //x = x0 ;
        //y = y0 ;
        std::cout << "Starting Solvar-B" << std::endl;
    }

    void step() {
        y += -y*dx;
        x += dx;
    }

    void solve() {
        while (x < 1.0) {
            step();
            std::cout <<  x << " " << y << std::endl;
        }
    }

    void print() {
        double y_true=exp(-x);
        std::cout << "x: " << x << ", y: " << y << ", error" << y-y_true << std::endl;
    }
};

