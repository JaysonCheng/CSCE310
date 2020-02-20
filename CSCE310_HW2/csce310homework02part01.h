/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 1
*/

#ifndef CSCE310HOMEWORK02PART01_H
#define CSCE310HOMEWORK02PART01_H
#include <vector>
using namespace std;

// A struct element which contains a double variable and a boolean value 
// (true for starting point of interval & false for ending point of interval)
struct List{
  double val; 
  bool startOrEnd;
};

// A function that should take two (2) vectors of n double values each as input and return the 
// maximum number of open intervals that overlap at a single point.
int overlappingIntervals( vector<double> start, vector<double> end );

#endif

