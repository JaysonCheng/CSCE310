/**
 * Name: Jayson Cheng
 * NUID: 28638995
 * Assignment 4
 */

#include <vector>
#include "csce310homework04part01.h"
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

// Comaprator function to sort capacity in struct in ascending order
bool compareCap(const blockData &x, const blockData &y){
  return x.capacity < y.capacity;
}

// Function to return the minimum value
int findMin(int x, int y){
  return (x < y ? x : y);
}

// Main function to return the greatest number of blocks that can be stacked on top of each other
int tallestTower( vector<int> weight , vector<int> capacity ){
  int n = weight.size();

  // Declare a struct array that holds object that contains weight, capacity, and remaining capacity
  vector<blockData> blocks = {};
  for(int i = 0; i < n; i++){
    // Add elements into the struct array
    blocks.push_back({weight[i], capacity[i], capacity[i] - weight[i]});
  }

  // Sort the struct array according to increasing order of capacity
  sort(blocks.begin(), blocks.end(), compareCap);

  // Declare a 2D array with size of number of blocks for row and number of blocks + 1 for 
  // column(keep track of maximum height)
  int maxBlocks[n][n + 1];
  
  for(int i = 0; i < n; i++){
    // Initialize column 0 with a maximum value
    maxBlocks[i][0] = INT16_MAX;
    for(int j = 0; j <= n; j++){
      // Initialize row 0 with a maximum value except maxBlocks[0][1]
      if(i == 0){
        if(j == 1){
          // Set maxBlocks[0][1] to the weight of the block which have the lowest capacity (height = 1)
          maxBlocks[i][j] = blocks[i].weight;
          continue;
        } else {
          maxBlocks[i][j] = INT16_MAX;
          continue;
        } 
      }
      
      // Update to weight of the previous stack
      maxBlocks[i][j] = maxBlocks[i - 1][j];

      // Condition to check if the remaining capacity is sufficient to hold the previous blocks
      if(maxBlocks[i - 1][j - 1] <= blocks[i].remCapacity){
        // Get the minimum weight of the stack
        maxBlocks[i][j] = findMin(maxBlocks[i][j], maxBlocks[i - 1][j - 1] + blocks[i].weight);
      }
    }
  }

  // Initialize the maximum height of tower
  int maxHeight = 0; 

  for(int j = n; j > 0; j--){
    // Condition the check the last row of maxBlock array to obtain the greatest height
    if(maxBlocks[n - 1][j] < INT16_MAX){
      maxHeight = j;
      break;
    }
  }

  return maxHeight;
}

