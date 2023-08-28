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
void primeFactorization(int, vector<int> &);

//Driver Function
int main(int argc, char* argv[]){
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    vector<int> primesM;
    vector<int> primesN;

    

    return 0;
}

//Function Definitions
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