/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2 Part 1
*/

#include <algorithm>
#include <vector>

#include "csce310homework02part01.h"

using namespace std;

// Comparator for val in increasing order for Struct List
bool cmpByVal(List a, List b){
  return a.val < b.val;
}

// Merge two vectors and sort them in increasing order
List *mergeSort( vector<double> start, vector<double> end){
  int i = 0;
  int j = 0;
  List *arr = new List[sizeof(start) + sizeof(end)];

  // Append the starting point in the vector to the beginning of arr
  while(i < start.size()){
    arr[i].val = start[i];
    arr[i].startOrEnd = true;
    i++;
  }

  // Append the ending point in the vector to the arr after finish appending all the starting points
  while(j < end.size()){
    arr[i].val = end[j];
    arr[i].startOrEnd = false;
    j++;
    i++;
  }

  // Sort them in increasing order
  sort(arr, arr + start.size() + end.size(), cmpByVal);

  return arr;
}

// A function that should take two (2) vectors of n double values each as input and return the 
// maximum number of open intervals that overlap at a single point.
int overlappingIntervals( vector<double> start , vector<double> end ){
  int prevMax = 0;
  int max = 0;
  List *arr = mergeSort(start, end);
  int size = start.size() + end.size();

  // Loop through the sorted merged array
  for(int i = 0; i < size; i++){
    // Increment the counter by 1 if it is a starting point
    if(arr[i].startOrEnd == true){
      prevMax++;
      // update the maximum number of open intervals that overlapk[\k]
      if(prevMax > max){
        max = prevMax;
      }
    // Decrease the counter by 1 if it is an ending point
    } else {
      prevMax--;
    }
  }

  // Condition to check if no overlapping occurs
  if(max == 1){
    return 0;
  }

  return max;
}
