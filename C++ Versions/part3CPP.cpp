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

//Class Prototypes
class node;

//Function Prototypes
void primeFactorization(int, primeFactor*);



//Driver Function
int main(int argc, char* argv[]){
    //Variables used to calculate the GCD
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);
    primeFactor *primeListMHead;
    primeFactor *primeListNHead;
}

//Class Definitions
/*
    Class Name: primeFactor
    Purpose:    Node for a linked list where the prime factor of a given value is stored and then how many times 
                that said value can be factored by the given prime factor.
*/
class primeFactor{
    public:
        int factor; 
        int factorPower;
        primeFactor *nextNode;
    private:
        primeFactor();
};

//Function Definitions
void primeFactorizations(int x, primeFactor *primeFactorX){
    if((x == 2) || (x == 1)){
        primeFactorX = new primeFactor;
        
    }
    else{
        while(x%2 == 0){
            
        }
    }
}

primeFactor::primeFactor(){
    factor = 0;
    factorPower = 0;
    nextNode = NULL;
}