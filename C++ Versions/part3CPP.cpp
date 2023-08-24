/*
    Name: Nol Patterson
    Date: 8/24/2023
    File Name: part3CPP.cpp
    Purpose: Write a program to execute the "Middle School" Algorithm for computing gcd
*/
//Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//Function Prototypes
void primeFactorization(int, vector<int>&);

//Classes
//Node will be used to form a linked list of the prime factorization of a number
//val will be used to store a prime number that is a factor of a given value, and 
//  how many times that value can be factored by the given val is represented by valPower
class node{
    int val;
    int valPower;
};

//Driver Function
int main(int argc, char* argv[]){
    //Variables used to calculate the GCD
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    //Vectors to store the prime factorizations of m and n respectively
    vector<int> vectorm;
    vector<int> vectorn;
}

//Function Definitions
void primeFactorizations(int x, vector<int> &vectorx){
    if((x == 2) || (x == 1)){
        vectorx.push_back(x);
    }
    else{
        while(x%2 == 0){
            
        }
    }
}