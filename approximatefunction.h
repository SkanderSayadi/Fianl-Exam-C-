//
// Created by Pc on 12/01/2018.
//

#ifndef EXAMEN_APPROXIMATEFUNCTION_H
#define EXAMEN_APPROXIMATEFUNCTION_H

#include<iostream>
#include <cmath>

using namespace std;

double approximation(double PV, int n, double c , double d, double FV){
    double x;
    x = 2 * (c + ((FV - PV) / (n + d))) / (FV + PV);
    return x ;
}



#endif //EXAMEN_APPROXIMATEFUNCTION_H
