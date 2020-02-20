/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 2
*/

#include <vector>
#include "csce310homework02part02.h"
#include <cmath>
#include <iostream>

using namespace std;

// determine if two arrays has at least one common element
bool intersect(vector<double> numbers, vector<double> compare, double sum){
    int i = 0;
    int j = 0;

    while( i < numbers.size() && j < compare.size()){
        // condition to ensure only compare sum of unique element
        if(numbers[i] < compare[j] || compare[j] * 2 == sum){
            i++;
        } else if(numbers[i] > compare[j] || compare[j] * 2 == sum){
            j++;
        } else {
            return true;
        }
    }
    return false;
}

// return true if two unique values in the array sum to the quantity of the 
// second input value
bool sumToN( vector<double> numbers , double sum ){
    vector<double> compare;
    double cmpVal = 0;

    // take the diff value and put it into an array
    for(int i = 0; i < numbers.size(); i++){
        cmpVal = sum - numbers[i];
        compare.insert(
            compare.begin(), cmpVal);
    }

    // comparing if there is a common element between the given array and
    // and the array that contains the difference value
    if(intersect(numbers, compare, sum)){
        return true;
    }

return false;
}



