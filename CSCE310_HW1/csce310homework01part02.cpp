#include "csce310homework01part02.h"
#include <string>
#include <iostream>

using namespace std;

bool leftToRight = true;
bool rightToLeft = false;
struct Elements
{
  /* data */
  char value;
  bool dir;
};

Elements *mapValuesToArrow(string word){
  Elements *arr = new Elements[word.length()];
  for(int i = 0; i < word.length(); i++){
    arr[i].value = word[i];
    arr[i].dir = rightToLeft;
  }
  return arr;
}

char getMobileElement(Elements *arr, int size){
  char mobile = 0;
  char prevMobile= 0;

  for(int i = 0; i < size; i++){
    if(i == 0 && arr[i].dir == rightToLeft){
      continue;
    }

    if(arr[i].dir == rightToLeft && i != 0){
      if(arr[i].value > arr[i - 1].value && arr[i].value > prevMobile){
        mobile = arr[i].value;
        prevMobile = mobile;
      }
    }

    if(i == size - 1 && arr[i].dir == leftToRight){
      continue;
    }

    if(arr[i].dir == leftToRight && i != size - 1){}
      if(arr[i].value > arr[i + 1].value && arr[i].value > prevMobile){
        mobile = arr[i]. value;
        prevMobile = mobile;
      }
  }

  return mobile;
}

void swap(Elements *i, Elements *j){
  Elements temp = *i;
  *i = *j;
  *j = temp;
}

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

void printOnePerm(Elements *arr, int size){
  char mobile = getMobileElement(arr, size);
  int mobileIndex = getMobileIndex(arr, mobile);

  if(arr[mobileIndex].dir == rightToLeft){
    swap(arr[mobileIndex], arr[mobileIndex - 1]);
  } else if(arr[mobileIndex].dir == leftToRight){
    swap(arr[mobileIndex], arr[mobileIndex + 1]);

  }

  for(int i = 0; i < size; i++){
    if(arr[i].value > mobile){
      if(arr[i].dir == rightToLeft){
        arr[i].dir = leftToRight;
      } else if(arr[i].dir == leftToRight){
        arr[i].dir = rightToLeft;
      }
    }
  }

  for(int i = 0; i < size; i++){
    cout << arr[i].value;
  }
  cout << endl;
}

int factorial(int size){
  int fact = 1;
  for (int i = 1; i <= size; i++){
    fact *= i;
  }
  return fact;
}

void printPermutations(string word)
{
  Elements *arr = mapValuesToArrow(word);
  int size = word.length();
  char a = getMobileElement(arr, size);

  cout << word << endl;
  for(int i = 0; i < factorial(size) - 1; i++){
    printOnePerm(arr, size);
  }
}
