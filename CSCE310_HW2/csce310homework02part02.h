/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 2
*/

#ifndef CSCE310HOMEWORK02PART02_H
#define CSCE310HOMEWORK02PART02_H
#include <vector>
using namespace std;

// determine if two arrays has at least one common element
bool intersect( vector<double> numbers, vector<double> compare, double sum );

// return true if two unique values in the array sum to the quantity of the 
// second input value
bool sumToN( vector<double> numbers, double sum );

#endif



