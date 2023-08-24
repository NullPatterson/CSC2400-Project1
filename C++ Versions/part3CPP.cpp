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
#include <math>
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
    primeFactor *primeListMHead = NULL;
    primeFactor *primeListNHead = NULL;
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
    //Impossible Case
    if(x < 2){
        cout << endl << "UNDEFINED: By definition a prime number is an integer greater than or equal to 2." << endl;
        cout << "Your input: " << x << "does not meet this criteria please try again." << endl << endl;
    }
    //Base Case
    if(x == 2){
        curNode = new primeFactor(x);
        //curNode->incrementPower();
        return primeFactorX;
    }
    else{
        //Seeing how many time 2 factors into given value
        while(x%2 == 0){
            //Allocating the head of the linked list if one does not exist
            if(curNode == NULL){
                curNode = new primeFactor(2);
            }
            //Increasing the count for the number of times 2 factors into x
            else{
                curNode->incrementPower();
            }
            x = x/2;
        }
        for(int i = 3; i <= sqrt(x); i = i +2){
            while(x%i == 0){
                if(curNode == NULL)
            }
        }
    }
    return primeFactorX;
}

//primeFactor Function Definitions
/*
    Function Name: primeFactor()
    Purpose: Constructor for the primeFactor class
*/
primeFactor::primeFactor(int givenFactor){
    factor = givenFactor;
    factorPower = 1;
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