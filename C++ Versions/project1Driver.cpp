/*
    Name: Nol Patterson
    Date: 8/29/2023
    File Name: project1.cpp
    Purpose: Execute 3 different Algorithms to calculate the gcd of two given numbers taken from the command line
             Euclid Algorithm
             Consecutive Integer Checking Algorithm
             "Middle School Algorithm"
*/
//Libaries and Header Files
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include "p1Header.h"
using namespace std;

//Driver Function
int main(int argc, char* argv[]){
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    
    part1(m, n);
    part2(m, n);
    part3(m, n);

    return 0;
}

//Function Definitions
//PART 1
/*
    Function Name: part1()
    Purpose: Contain all calculations and function calls related to part 1
*/
void part1(int a, int b){
    //Coeefficients for a and b respectively such that ax+by = gcd(a, b)
    int x, y;

    cout << endl << "PART 1:" << endl;

    //Calculating the gcd and passing x and y by reference
    int gcd = euclidianGCD(a, b, &x, &y);

    //Outputting the following 3 lines all on one line. Seperated here for readibility while editing
    //Output should look like "gcd(a, b) = (a)(x) + (b)(y) = gcd"
    cout << "gcd(" << a << ", " << b << ") = "; 
    cout << "(" << a << ")(" << x << ") + (" << b << ")(" << y << ") = ";
    cout << gcd << endl;
}

/* 
    Function Name: euclidianGCD()
    Purpose: A recursive function used to calculate the gcd using of two given numbers along with coefficients 
             for said given numbers such that ax + by = gcd
*/
int euclidianGCD(int a, int b, int *x, int *y){
    //Base case
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    //Variables to store the calues from the recursive call.
    int xRecur, yRecur;
    //Recursive Call
    //The first paramters are "b%a" and "a" as per the definition of the Euclidian Algorithm
    int gcd = euclidianGCD(b%a, a, &xRecur, &yRecur);

    //Updating coefficients after recursive call;
    *x = yRecur - ((b/a)*xRecur);
    *y = xRecur;

    return gcd;
}