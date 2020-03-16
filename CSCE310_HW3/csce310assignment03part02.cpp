// Name: Jayson Cheng
// NUID: 28638995
// Assignment 3

#include <vector>
#include <iostream>
#include "csce310assignment03part02.h"

using namespace std;

/**
 * A function that returns the n × n vector representing the matrix computed after 
 * the ith stage of Floyd’s algorithm
 **/
vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){
  // Get the size of matrix
  int v = adjacencyMatrix.size();

  for(int c = 0; c < i; c++){
    for(int a = 0; a < v; a++){
      for(int b = 0; b < v; b++){

        // Since -1 represents INFINITY, if vertex c is infinity from a to b,
        // then move on to next index
        if(adjacencyMatrix[a][c] ==  -1 || adjacencyMatrix[c][b] == -1){
          continue;
        }
        // If vertex c is the shortest path from a to b, update the value
        if(adjacencyMatrix[a][b] > (adjacencyMatrix[a][c] + adjacencyMatrix[c][b]) || adjacencyMatrix[a][b] < 0){
          adjacencyMatrix[a][b] = adjacencyMatrix[a][c] + adjacencyMatrix[c][b];
        }
      }
    }
  }

  return adjacencyMatrix;
}
