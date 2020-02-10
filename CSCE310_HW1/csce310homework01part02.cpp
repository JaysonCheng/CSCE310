/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 1
*/

#include "csce310homework01part02.h"
#include <string>
#include <iostream>

using namespace std;

// Initialize the direction arrow 
bool leftToRight = true;
bool rightToLeft = false;

// Create a struct array to map each character in the words with a direction arrow
// and initialize the direction arrows pointing from right to left
Elements *mapValuesToArrow(string word){
  // Initialize array
  Elements *arr = new Elements[word.length()];
  for(int i = 0; i < word.length(); i++){
    arr[i].value = word[i];
    arr[i].dir = rightToLeft;
  }
  return arr;
}

// Find the largest mobile element
char getMobileElement(Elements *arr, int size){
  char mobile = 0;
  char prevMobile= 0;

  for(int i = 0; i < size; i++){
    // Condition to check if the index is at 0 and the arrow is pointing from right to left,
    // if it is, move to the next index
    if(i == 0 && arr[i].dir == rightToLeft){
      continue;
    }

    // Condition to find the largest mobile element when the arrow is pointing from right to left
    if(arr[i].dir == rightToLeft && i != 0){
      if(arr[i].value > arr[i - 1].value && arr[i].value > prevMobile){
        mobile = arr[i].value;
        prevMobile = mobile;
      }
    }

    // Condition to check if the index is at last index and the arrow is pointing from left to right,
    // if it is, move to the next index
    if(i == size - 1 && arr[i].dir == leftToRight){
      continue;
    }

    // Condition to find the largest mobile element when the arrow is pointing from left to right
    if(arr[i].dir == leftToRight && i != size - 1){
      if(arr[i].value > arr[i + 1].value && arr[i].value > prevMobile){
        mobile = arr[i]. value;
        prevMobile = mobile;
      }
    }
  }

  return mobile;
}

// Swap the elements in the struct array
void swap(Elements *i, Elements *j){
  Elements temp = *i;
  *i = *j;
  *j = temp;
}

// Get the index for the mobile element
int getMobileIndex(Elements *arr, char mobile){
  int i = 0;
  while(i < sizeof(arr)){
    if(arr[i].value == mobile){
      return i;
    } else {
      i++;
    }
  }
  return 0;
}

// Print one permutation given the input of struct array and the size of the string
void printOnePerm(Elements *arr, int size){
  // Find the largest mobile element and the index of the mobile element
  char mobile = getMobileElement(arr, size);
  int mobileIndex = getMobileIndex(arr, mobile);

  // Condition to swap the mobile element with the element before it if the direction
  // is from right to left
  if(arr[mobileIndex].dir == rightToLeft){
    swap(arr[mobileIndex], arr[mobileIndex - 1]);

  // Condition to swap the mobile element with the element after it if the direction
  // is from left to right
  } else if(arr[mobileIndex].dir == leftToRight){
    swap(arr[mobileIndex], arr[mobileIndex + 1]);
  } 

  // Update the direction of the element if there is a larger element in the array than 
  // the mobile element
  for(int i = 0; i < size; i++){
    if(arr[i].value > mobile){
      if(arr[i].dir == rightToLeft){
        arr[i].dir = leftToRight;
      } else if(arr[i].dir == leftToRight){
        arr[i].dir = rightToLeft;
      }
    }
  }

  // Print out the permutation
  for(int i = 0; i < size; i++){
    cout << arr[i].value;
  }
  cout << endl;
}

// Calculate the factorial of the size of string to generate 
// n! of permutations
int factorial(int size){
  int fact = 1;
  for (int i = 1; i <= size; i++){
    fact *= i;
  }
  return fact;
}

// Generate all fo the possible permutations for the string
void printPermutations(string word)
{
  // Declare a struct array for the string
  Elements *arr = mapValuesToArrow(word);
  int size = word.length();

  cout << word << endl;
  for(int i = 0; i < factorial(size) - 1; i++){
    printOnePerm(arr, size);
  }
}
