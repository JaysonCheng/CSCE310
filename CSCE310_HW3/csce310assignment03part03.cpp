// Name: Jayson Cheng
// NUID: 28638995
// Assignment 3

#include <vector>
#include "csce310assignment03part03.h"
#include <iostream>

using namespace std;

/** 
 * Take a vector of integers (coefficients of a polynomial) and
 * another integer as input and return the value of polynomial, 
 * evaluated at that particular integer
**/
int hornerRule( vector<int> xs , int ys ){
  // Let sum equals to the first element of the vector
  int sum = xs[0];
  for(int i = 1; i < xs.size(); i++){
    sum = xs[i] + (sum * ys);
  }
  return sum;
}