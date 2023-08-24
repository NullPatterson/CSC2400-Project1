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

//Function Prototypes
int euclidianGCD(int, int, int*, int*);

//Driver function
int main(int argc, char* argv[]){
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    //Coefficients for m and n respectively such that mx+ny = gcd(m, n)
    int x, y;

    //Calculating the gcd and passing x and y back through the functions
    int gcd = euclidianGCD(m, n, &x, &y);
    cout << "gcd(" << m << ", " << n << ") = mx + ny = ";
    cout << "(" << m << ")(" << x << ") + (" << n << ")(" << y << ") = " << gcd << endl;

    return 0;
}

//Function Definitions
/*
    Function Name: euclidianGCD()
    Purpose: Calculate the gcd between a, b and the coefficients c and d such that ac+bd = gcd(a, b)
*/
int euclidianGCD(int a, int b, int *c, int *d){
    //Base case
    if(a == 0){
        *c = 0;
        *d = 1;
        return b;
    }

    //Variables to store the values from the recursive call.
    int cR, dR;
    //Recursive call
    int gcd = euclidianGCD(b%a, a, &cR, &dR);

    //Updating after recursive call
    *c = dR - ((b/a)*cR);
    *d = cR;

    return gcd;
}