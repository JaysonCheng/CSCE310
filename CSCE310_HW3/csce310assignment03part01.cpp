// Name: Jayson Cheng
// NUID: 28638995
// Assignment 3

#include <vector>
#include <algorithm>
#include <iostream>

#include "csce310assignment03part01.h"

using namespace std;

/**
 * Structure to represent a weighted edge in a directed graph
**/
struct Edge{
  int src;
  int dest;
  int weight;
};

/**
 * Structure to represent a subset for union rank and path compression
**/
struct Subset{
  int parent;
  int rank;
};

/**
 * Comparator for quick sort algorithm by the values of weight in descending order
**/
bool compareWeight( Edge a, Edge b ){
  return a.weight > b.weight;
}

/**
 * Sort the weighted edges in descending order from the input of matrix
**/
vector< Edge > sortEdges( vector< vector<double> > adjacencyMatrix ){
  // Declare an empty vector for sorted edges
  vector < Edge > edges = {};
  int columnSize = adjacencyMatrix.size();
  int rowSize = adjacencyMatrix[0].size();

  // Loop through the matrix and store the weighted edges into the vector
  for(int i = 0; i < rowSize; i++){
    for(int j = 0; j < columnSize; j++){
      if(adjacencyMatrix[i][j] == 0){
        continue;
      } else {
        edges.push_back({i, j, (int) adjacencyMatrix[i][j]});
      }
    }
  }

  // Sort the vector according to the weight in descending order
  sort(edges.begin(), edges.end(), compareWeight);

  return edges;
}

/**
 * Path compression technique to find the root of the element
**/
int findSet(vector< Subset> subsets, int i){
  // Find the root by recursively call and update the parent value of i with root
  if(subsets[i].parent != i){
    subsets[i].parent = findSet(subsets, subsets[i].parent);
  }

  return subsets[i].parent;
}

/**
 * Main function to calculate the maximum spanning tree
**/
double maximumST( vector< vector<double> > adjacencyMatrix ){
  // Declare a struct vector to hold the sorted edges
  vector < Edge > sortedEdges = sortEdges(adjacencyMatrix);
  // Number of vertex is equals to the size of input matrix
  int v = adjacencyMatrix.size();
  // Number of edges is equals to the size of sortedEdge vector
  int e = sortedEdges.size();
  int maxSt = 0;
  int i = 0;
  int j = 0;

  // Declare a Subset array with initialized parent as i and rank as 0
  vector< Subset > subsets(v);
  for(int i = 0; i < v; i++){
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  // While loop with condition of number of edges as v - 1
  // and size of sorted edges vector
  while(i < v - 1 && j < e){
    // Call findSet function for the source point and destination point
    // to determine the root of both points
    int a = findSet(subsets, sortedEdges[j].src);
    int b = findSet(subsets, sortedEdges[j].dest);

    // A cycle is not formed by when the roots for both points are different
    if(a != b){
      // Add the maximum weight of the edges
      maxSt += sortedEdges[j].weight;

      // Smaller rank tree is attached to higher rank tree
      if(subsets[a].rank > subsets[b].rank){
        subsets[b].parent = a;
      } else if(subsets[a].rank < subsets[a].rank){
        subsets[a].parent = b;
      } else {
        // If both ranks are the same, then make root of source point as the
        // parent of destination point and increase the rank by one
        subsets[b].parent = a;
        subsets[a].rank ++;
      }
      i++;
    }
    j++;
  }
  
  return maxSt;
}
