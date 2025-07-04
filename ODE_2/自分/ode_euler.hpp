#pragma once
#include <iostream>
#include <vector>

class ODE_euler {
    double y;   //private 外から操作不可
    double ym;
    double x;
    double dx;
    double z;
    double zm;
public:         //外から操作可能
    double xmax;
    double c;


    ODE_euler(){
        std::cout << "Starting Solvar-A" << std::endl;
    }
    ODE_euler(double y0, double z0, double x0):y(y0), z(z0), x(x0)
    {
        //x = x0 ;
        //y = y0 ;
        std::cout << "Starting Solvar-B" << std::endl;
    }

    void initiakize(){
        dx = xmax / 100;
    }
    
    void step() {
        ym =y;
        zm =z;
        y = ym + dx * zm;
        z = zm - dx * ym;
        x += dx;
    }

    void solve() {
        while (x < xmax) {
            step();
            std::cout <<  x << " " << y << " " << z << std::endl;
        }
    }

    void print() {
        double y_true=exp(-x);
        std::cout << "x: " << x << ", y: " << y << ", dy/dx:" << z << ", error" << y-y_true << std::endl;
    }
};

