/*
    Name: Nol Patterson
    Date: 8/24/2023
    File Name: part3Vector.cpp
    Purpose: Write a program to execute the "Middle School" Algorithm for computing gcd
*/
//Libraries
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//Function Prototypes
void commonFactors(vector<int> &, vector<int> &, vector<int> &);
int gcdCalculation(int, int, vector<int> &, vector<int> &);
void primeFactorization(int, vector<int> &);


//Driver Function
int main(int argc, char* argv[]){
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    int GCD;
    vector<int> primesM;
    vector<int> primesN;

    GCD = gcdCalculation(m, n, primesM, primesN);

    return 0;
}

//Function Definitions
/*
    Function Name: commonFactors()
    Purpose: Determine all common factors from two sets of data
*/
void commonFactors(vector<int> &vectorX, vector<int> &vectorY, vector<int> &vectorC){
    vector<int> *smallerVec, *largerVec;
    int curLElem = 0;

    if(vectorX.size() < vectorY.size()){
        smallerVec = &vectorX;
        largerVec = &vectorY;
    }
    else{
        smallerVec = &vectorY;
        largerVec = &vectorX;
    }
    
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
    Function Name: gcdCalculation()
    Purpose: Determine the gcd of two integers by finding the product of all of their common
             prime factors
*/
int gcdCalculation(int a, int b, vector<int> &vectorA, vector<int> &vectorB){
    vector<int> commonVector;
    int gcd = 1;

    primeFactorization(a, vectorA);
    primeFactorization(b, vectorB);

    commonFactors(vectorA, vectorB, commonVector);

    for(int i = 0; i < commonVector.size(); ++i){
        gcd = gcd * commonVector[i];
    }
    return gcd;
}

/*
    Function Name: primeFactorization()
    Purpose: Factor a given integer into its prime factors, and store the factors in a vector passed by reference
*/
void primeFactorization(int x, vector<int> &vectorX){
    //Base Case
    if(x == 2){
        vectorX.push_back(2);
    }
    //Impossible Case
    else if(x < 2){
        vectorX.push_back(0);
    }
    else{
        while(x%2 == 0){
            vectorX.push_back(2);
            x = x/2;
        }
        for(int i = 3; i < ceil(sqrt(x)); i += 2){
            while(x%i == 0){
                vectorX.push_back(i);
                x = x/i;
            }
        }
    }
}

