/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 1
*/

#include "csce310homework01part01.h"

using namespace std;

// calculate the product of the digits inthe input decimal integer
unsigned long long int productOfDigits( unsigned long long int digits ){
  unsigned long long int product = 1;
  while(digits != 0){
    product = product * (digits % 10);
    // shift digits to right by 1
    digits = digits / 10;
  }
  return product;
}
