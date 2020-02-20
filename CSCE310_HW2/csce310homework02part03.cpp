/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 3
*/

#include <vector>
#include "csce310homework02part03.h"
#include <cmath>
#include <iostream>

using namespace std;

// Declare global variables
// Level is the number of times required to successfully find the certain element in 
// the array by binary search
double total = 0;
int level = 1;

// A function to calculate the total number of times that a binary search is executed
void calBinarySearch( vector<int> numbers, int l, int r, int level){
  int size = r - l + 1;

  // Base case for recursion
  if (size == 0) {
  } else if(size == 1) {
    total += level;
  } else {
    // Determine the middle element
    int m = l + (r - l) / 2;
    // Add level to the total number of times
    total += level;
    // Increase the level by 1 for every recursion
    calBinarySearch(numbers, l, m -1, level + 1); 
    calBinarySearch(numbers, m + 1, r, level + 1);
  }
}

// A function to determine the average number of comparisons that would be required to
// successfully find an element in the array using binary search
double averageComparisons( vector<int> numbers ){
  int size = numbers.size();
  calBinarySearch(numbers, 0, size - 1, level);
  double avg = total / size;
  return avg;
}

