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
#include <cmath>
using namespace std;

//Class Prototypes
class primeFactor;

//Function Prototypes
int gcdMiddleSchool(int, int); 
primeFactor *primeFactorizations(int, primeFactor*);
primeFactor *likeFactors(primeFactor*, primeFactor*);
void nodeModificationCheck(primeFactor*);



//Driver Function
int main(int argc, char* argv[]){
    //Variables used to calculate the GCD
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;

    int GCD = gcdMiddleSchool(m, n);

    if(GCD == 0){
        cout << "GCD for the values given is undefined." << endl;
        cout << "Please ensure you have entered positive integers greater than or equal to 2." << endl;
    }
    else{
        cout << "gcd(" << m << ", " << n << ") = " << GCD << endl; 
    }
}

//Class Definitions
/*
    Class Name: primeFactor
    Purpose:    Node for a linked list where the prime factor of a given value is stored and then how many times 
                that said value can be factored by the given prime factor.
*/
class primeFactor{
    public:
        primeFactor *nextNode;
        primeFactor(int);
        primeFactor(int, int);
        ~primeFactor();
        int getFactor();
        int getFactorPower();
        void incrementPower();
    private:
        int factor; 
        int factorPower;      
};

//Function Definitions
int gcdMiddleSchool(int a, int b){
    primeFactor *primeListAHead = NULL;
    primeFactor *primeListBHead = NULL;
    primeFactor *commonFactors = NULL;
    int gcd = 1;

    primeListAHead = primeFactorizations(a, primeListAHead);
    primeListBHead = primeFactorizations(b, primeListBHead);
    //primeFactorizations(a, primeListAHead);
    //primeFactorizations(a, primeListBHead);

    commonFactors = likeFactors(primeListAHead, primeListBHead);

    if(commonFactors == NULL){
        return 0;
    }

    while(commonFactors != NULL){
        gcd = gcd*(commonFactors->getFactor()*commonFactors->getFactorPower());
        commonFactors = commonFactors->nextNode;
    }

    return gcd;
}

primeFactor *primeFactorizations(int x, primeFactor *primeFactorX){
    //Pointer to allocate and track nodes
    primeFactor *curNode = primeFactorX;
    //Impossible Case
    if(x < 2){
        cout << endl << "UNDEFINED: By definition a prime number is an integer greater than or equal to 2." << endl;
        cout << "Your input: " << x << "does not meet this criteria please try again." << endl << endl;
    }
    //Base Case
    else if(x == 2){
        curNode = new primeFactor(x);
        //curNode->incrementPower();
        return primeFactorX;
    }
    else{
        //Seeing how many time 2 factors into given value
        while(x % 2 == 0){
            //Allocating the latested node of the linked list
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
            //Ensuring the next node used will be empty(NULL) if its not already
            if(curNode != NULL){
                curNode = curNode->nextNode;
            }
            //Checking to see if the current value is divisible by i. 
            while(x%i == 0){
                if(curNode == NULL){
                    curNode = new primeFactor(i);
                }
                else{
                    curNode->incrementPower();
                }
                x = x/i;
            }
        }
    }
    return primeFactorX;
}

primeFactor *likeFactors(primeFactor *primeList1, primeFactor *primeList2){
    //Declaring a pointer for a linked list to track like factors
    primeFactor *commonFactorListHead = NULL;
    primeFactor *curCommonFactor = commonFactorListHead;
    
    while((primeList1 != NULL) && (primeList2 != NULL)){
        if(primeList1->getFactor() < primeList2->getFactor()){
            primeList1 = primeList1->nextNode;
        }
        else if(primeList1->getFactor() > primeList2->getFactor()){
            primeList2 = primeList2->nextNode;
        }
        else{
            if(primeList1->getFactorPower() < primeList2->getFactorPower()){
                curCommonFactor = new primeFactor(primeList1->getFactor(), primeList1->getFactorPower());
            }
            else{
                curCommonFactor = new primeFactor(primeList2->getFactor(), primeList2->getFactorPower());
            }
            curCommonFactor = curCommonFactor->nextNode;
        }
    }

    return commonFactorListHead;
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

primeFactor::primeFactor(int givenFactor, int givenPower){
    factor = givenFactor;
    factorPower = givenPower;
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

void primeFactor::incrementPower(){
    ++factorPower;
}