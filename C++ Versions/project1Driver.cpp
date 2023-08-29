/*
    Name: Nol Patterson
    Date: 8/29/2023
    File Name: project1.cpp
    Purpose: Execute 3 different Algorithms to calculate the gcd of two given numbers taken from the command line
             Part 1: Euclid Algorithm
             Part 2: Consecutive Integer Checking Algorithm
             Part 3: "Middle School Algorithm"
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
    int gcd;
    //gcd = euclidianGCD(a, b, &x, &y);
    if((a < 0) && (b > 0)){
        gcd = euclidianGCD(-a, b, &x, &y);
    }
    else if((a > 0) && (b < 0)){
        gcd = euclidianGCD(a, -b, &x, &y);
    }
    else{
        gcd = euclidianGCD(a, b, &x, &y);
    }


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



//PART 2
/*
    Function Name: part2()
    Purpose: Contain all calculations and function calls related to part 2
*/
void part2(int a, int b){
    cout << endl << endl << "PART 2:" << endl;
    
    //GCD Calculation
    int gcd;
    if((a < 0) && (b < 0)){
        gcd = consecutiveGCD(-a, -b, min(-a, -b));
    }
    else if(a < 0){
        gcd = consecutiveGCD(-a, b, min(-a, b));
    }
    else if(b < 0){
        gcd = consecutiveGCD(a, -b, min(a, -b));
    }
    else{
        gcd = consecutiveGCD(a, b, min(a, b));
    }

    //Outputting GCD
    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
}

/*
    Function Name: consecutiveGCD()
    Purpose: Recursively call itself to compare a mod t and b mod t until both = 0
    Paramaters: a one of two variables being compared to find the GCD
                b one of two variables being compared to find the GCD
                t a variable that was assigned min(a, b) and will be decremented once per call of the function until the GCD is found
*/
int consecutiveGCD(int a, int b, int t){
    //Using mod(%) to determine if t is a divisor of a value
    if((a%t == 0) && (b%t == 0)){
        return t;
    }
    else{
        t = consecutiveGCD(a, b, t-1);
    }
    return t;
}

//PART 3
/*
    Function Name: part3()
    Purpose: Contain all calculations and function calls related to part 3
*/
void part3(int a, int b){
    cout << endl << endl << "PART 3:" << endl;

    //Vectors used to store the prime factors of a and b respectively
    vector<int> primesA;
    vector<int> primesB;

    //GCD Calculation
    int gcd = middleSchoolGCD(a, b, primesA, primesB);

    //Outputting the GCD
    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
}

/*
    Function Name: commonFactors()
    Purpose: Determine all common factors from two sets of data
*/
void commonFactors(vector<int> &vectorA, vector<int> &vectorB, vector<int> &vectorC){
    //Vector pointers to track which vector out of vectorA and vectorB, is smaller
    vector<int> *smallerVec, *largerVec;
    //Integer used to calculate the latest checked element int the larger vector
    int curLElem = 0;

    //Assigning pointers
    if(vectorA.size() < vectorB.size()){
        smallerVec = &vectorA;
        largerVec = &vectorB;
    }
    else{
        smallerVec = &vectorA;
        largerVec = &vectorB;
    }
    
    //Iterating through vectorX and vectorY and comparing vector elements
    for(int i = 0; i < (*smallerVec).size(); ++i){
        while((*smallerVec)[i] > (*largerVec)[curLElem]){
            ++curLElem;
        }

        if((*smallerVec)[i] == (*largerVec)[curLElem]){
            vectorC.push_back((*smallerVec)[i]);
            ++curLElem;
        }
    }
}

/*
    Function Name: middleSchoolGCD()
    Purpose: Determine the gcd of two integers by finding the product of all of their common
             prime factors
*/
int middleSchoolGCD(int a, int b, vector<int> &vectorA, vector<int> &vectorB){
    //Vector used to store all common prime factors of a and b
    vector<int> commonVector;
    int gcd = 1;

    //Determining the prime factors of a and b and storing them in their respective vectors
    //Accomodating for negative integers
    if(a < 0){
        vectorA.push_back(-1);
        primeFactorization(-a, vectorA);
    }
    else{
        primeFactorization(a, vectorA);
    }
    if(b < 0){
        vectorB.push_back(-1);
        primeFactorization(-b, vectorB);
    }
    else{
        primeFactorization(b, vectorB);
    }

    //Calcualting common prime factors of a and b
    commonFactors(vectorA, vectorB, commonVector);

    //Calculating the gcd
    for(int i = 0; i < commonVector.size(); ++i){
        gcd = gcd * commonVector[i];
    }

    return gcd;
}

/*
    Function Name: primeFactorization()
    Purpose: Factor a given integer into its prime factors, and store the factors in a vector passed by reference
*/
void primeFactorization(int z, vector<int> &vectorZ){
    //Base Case
    if(z == 2){
        vectorZ.push_back(2);
    }
    //Impossible Case
    else if(z < 2){
        vectorZ.push_back(0);
    }
    else{
        while(z%2 == 0){
            vectorZ.push_back(2);
            z = z/2;
        }
        for(int i = 3; i < ceil(sqrt(z)); i += 2){
            while(z%i == 0){
                vectorZ.push_back(i);
                z = z/i;
            }
        }
    }
}