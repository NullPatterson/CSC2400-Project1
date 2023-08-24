/*
    Name: Nol Patterson
    Date: 8/24/2023
    File Name: part2CPP.cpp
    Purpose: Write a program to execute the Consecutive Integer Checking Algorithm for computing gcd
*/
//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int consecutiveGCD(int, int, int);

//Driver Function
int main(int argc, char* argv[]){
    //Variables to store the two numbers for the gcd calculated
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);

    int gcd = consecutiveGCD(m, n, min(m, n));

    cout << "gcd(" << m << ", " << n << ") = " << gcd << endl;
    return 0;
}

//Function Definitions
/*
    Function Name: consecutiveGCD()
    Purpose: Recursively call itself to compare m mod t and n mod t until both = 0
    Paramaters: M one of two variables being compared to find the GCD
                N one of two variables being compared to find the GCD
                T a variable that was assigned min(M, N) and will be decremented once per call of the function until the GCD is found
*/
int consecutiveGCD(int M, int N, int T){
    //Using mod (%) to determine if T is a divisor of a value.
    if(M%T == 0){
        if(N%T == 0){
            return T;
        }
        else{
            T = consecutiveGCD(M, N, T-1);
        }
    }
    else{
        T = consecutiveGCD(M, N, T-1);
    }
    return T;
}