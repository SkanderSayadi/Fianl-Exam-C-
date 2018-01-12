#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "cmake-build-debug/CMakeFiles/approximatefunction.h"
#include "cmake-build-debug/CMakeFiles/Target.h"

using namespace std;

int main() {
    double FV,PV, YieldToMaturity ,c,d;
    double couponValue,lbound, ubound,temp, tolerance;
    int N, Iteration , MAX_Iteration;


    cout << " Welcome To the YTM PROGRAM CALCULATOR! "<< endl;
    cout << " Reminder : The yield to maturity is the interest rate that makes the present value of the future coupon payments equal to the current bond price" << endl;

    cout << " Please, provide an annual coupon rate (c)"<< endl;
    cin >> c;

    do {
        cout << " Please, provide (d) the year fraction until next coupon payment as a number in [0,1] " << endl;
        cin >> d;

    }while( (d<0)||(d>1));

    do{
        cout << " Please, provide the number (N) of full years until maturity "<< endl;
        cin >> N;
    }while (N<0);


    do{
        cout << " Please, provide the present value (PV) of a bond "<< endl;
        cin >> PV;
    }while (PV<0);



    do{
        cout << " Please, provide the face (future) value (FV) of a bond "<< endl;
        cin >> FV;
    }while (FV<0);

    YieldToMaturity=0;
    tolerance = 0.0001;
    Iteration = 0;
    MAX_Iteration = 10000;

    // We want to approximate the YTM by setting two bounds ( upper and lower).
    // Then, We bisect the interval between the upper and lower until we are close enough.

    lbound=YTMapproximation(PV,N,c,d,FV)*0.95;
    ubound=YTMapproximation(PV,N,c,d,FV);
    temp=0;

    do{
        temp=ubound;
        ubound=ubound-(target(PV,N,c,FV,d,ubound)*(ubound-lbound)) /(target(PV,N,c,FV,d,ubound)-target(PV,N,c,FV,d,lbound));
        lbound=temp;
        Iteration=Iteration+1;
    }while((abs(target(PV,N,c,FV,d,ubound))> tolerance ) || (Iteration > MAX_Iteration));


    YieldToMaturity=lbound;

    cout << YieldToMaturity << " which is equivalent to " << (YieldToMaturity*100) <<"%";

}