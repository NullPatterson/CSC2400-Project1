/*
    Name: Nol Patterson
    Date: 8/23/2023
    File Name: extendedEuclidCPP
    Purpose: Write a program to execute the extended Euclid's Algorithm (ax+by=gcd(a,b))
*/
//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Main function
int main(int M, int N){
    int m = M;
    int n = N;
    //Coefficients for a and b respectively such that ax+by = gcd(a, b)
    int x, y;
    //Reserve variable, in order to move values around
    int r;

    //Base case
    if(m == 0){
        x = 0;
        y = 1;
        return n;
    }
    
    

    return 0;
}