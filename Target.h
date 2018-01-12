//
// Created by Pc on 12/01/2018.
//

#ifndef EXAMEN_TARGET_H
#define EXAMEN_TARGET_H


#include<iostream>
#include <cmath>

using namespace std;
double target(double PV,int n , double c ,double FV, double d, double ytm){
    double t;
    t=(c/ytm)*pow((1 + ytm),(1 - d)) + (FV - c / ytm) /pow((1 + ytm),(n + d)) - PV;
    return t ;

}

#endif //EXAMEN_TARGET_H
