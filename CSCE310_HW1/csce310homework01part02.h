/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 1
*/

#ifndef CSCE310HOMEWORK01PART02_H
#define CSCE310HOMEWORK01PART02_H

#include <string>

using namespace std;

// Declare a struct type that contains a char and a boolean value
struct Elements
{
  /* data */
  char value;
  bool dir;
};

// Create a struct array to map each character in the words with a direction arrow
// and initialize the direction arrows pointing from right to left
Elements *mapValuesToArrow(string word);

// Find the largest mobile element
char getMobileElement(Elements *arr, int size);

// Swap the elements in the struct array
void swap(Elements *i, Elements *j);

// Get the index for the mobile element
int getMobileIndex(Elements *arr, char mobile);

// Print one permutation given the input of struct array and the size of the string
void printOnePerm(Elements *arr, int size);

// Calculate the factorial of the size of string to generate 
// n! of permutations
int factorial(int size);

// Generate all fo the possible permutations for the string
void printPermutations( string word);

#endif

