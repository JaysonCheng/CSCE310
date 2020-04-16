/**
 * Name: Jayson Cheng
 * NUID: 28638995
 * Assignment 4
 */

#include <vector>
#include "csce310homework04part02.h"
#include <cmath>
#include <climits>
#include <iostream>
#include <cmath>

using namespace std;

// Main function to return the smallest difference in weight possible when dividing 
// those individuals into two (2) teams
int tugOfWar( vector<int> weight ){
  int n = weight.size();
  
  // Calculate the total sum of the elements in the vector
  double sum = 0;

  for(int i = 0; i < n; i++){
    sum += weight[i];
  }

  // Calculate half of the sum
  int halfSum = (int)ceil(sum / 2);

  // Declare a 2D array with size of number of elements for row and total amount of halfSum for column
  int arr[n + 1][halfSum + 1];

  for(int i = 0; i < n + 1; i++){
    // Since there is a possibility that all elements has an empty set when sum is 0, so it is true (1)
    arr[i][0] = 1;
    for(int j = 1; j < halfSum + 1; j++){
      // It is not possible to have subset when there is no elements, so it is false (0) except arr[0][0]
      if(i == 0){
        arr[i][j] = 0;
        continue;
      }

      // It is also possible to have the subset found in previous row when an element is added to the array
      arr[i][j] = arr[i - 1][j];

      // If the sum is greater than or equal to element at index i in weight vector, then apply the relation
      if(j >= weight[i - 1]){
        arr[i][j] = max(arr[i - 1][j - weight[i - 1]], arr[i - 1][j]);
      }
    }
  }

  // Find the closest weight to the halfSum since the array is partition into two sets which makes the 
  // total weight of one of the set is either equal or less than the half of the total sum of weight vector
  for(int j = halfSum; j >= 0; j--){
    if(arr[n][j] == 1){
      // return absolute value of subtracting twice of the closest weight to halfSum from total sum of weight to
      // obtain the smallest difference in weight
      return abs(sum - (2 * j));
    }
  }
}
