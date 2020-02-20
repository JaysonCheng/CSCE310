/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 3
*/

#ifndef CSCE310HOMEWORK02PART03_H
#define CSCE310HOMEWORK02PART03_H
#include <vector>
using namespace std;

// A function to calculate the total number of times that a binary search is executed
void calBinarySearch( vector<int> numbers, int l, int r, int level );

// A function to determine the average number of comparisons that would be required to
// successfully find an element in the array using binary search
double averageComparisons( vector<int> numbers );

#endif

