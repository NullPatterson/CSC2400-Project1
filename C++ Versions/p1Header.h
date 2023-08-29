/*
    Name: Nol Patterson
    Date: 8/29/2023
    File Name: p1Header.h
    Purpose: Header file for project1Driver.cpp
*/
#ifndef P1HEADER_H
#define P1HEADER_H
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//FUNCTION PROTOTYPES
//Part 1
void part1(int, int);
int euclidianGCD(int, int, int*, int*);

//Part2
void part2(int, int);
int consecutiveGCD(int, int, int);

//Part 3
void part3(int, int);
void commonFactors(vector<int> &, vector<int> &, vector<int> &);
int middleSchoolGCD(int, int, vector<int> &, vector<int> &);
void primeFactorization(int, vector<int> &);

#endif