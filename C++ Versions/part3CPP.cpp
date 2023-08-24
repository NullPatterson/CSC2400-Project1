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
class primeFactor;

//Function Prototypes
 primeFactor *primeFactorization(int, primeFactor*);



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
        primeFactor(int);
        ~primeFactor();
        int getFactor();
        int getFactorPower();
        int incrementPower();
    private:
        int factor; 
        int factorPower;
        primeFactor *nextNode;
};

//Function Definitions
primeFactor *primeFactorizations(int x, primeFactor *primeFactorX){
    //Pointer to allocate and track nodes
    primeFactor *curNode = primeFactorX;
    if(x == 2){
        curNode = new primeFactor(x);
        
        return curNode;
    }
    else{
        if(x%2 == 0){
            
        }
        while(x%2 == 0){
            
        }
    }
    return NULL;
}

//primeFactor Function Definitions
/*
    Function Name: primeFactor()
    Purpose: Constructor for the primeFactor class
*/
primeFactor::primeFactor(int givenFactor){
    factor = givenFactor;
    factorPower = 0;
    nextNode = NULL;
}

/*
    Function Name: ~primeFactor()
    Purpose: Destructor for the primeFactor class
*/
primeFactor::~primeFactor(){
    if(nextNode != NULL){
        delete nextNode;
    }
}

int primeFactor::getFactor(){
    return factor;
}

int primeFactor::getFactorPower(){
    return factorPower;
}

int primeFactor::incrementPower(){
    ++factorPower;
}