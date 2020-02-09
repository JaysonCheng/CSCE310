#include "csce310homework01part01.h"

using namespace std;

unsigned long long int productOfDigits( unsigned long long int digits ){
  unsigned long long int product = 1;
  while(digits != 0){
    product = product * (digits % 10);
    digits = digits / 10;
  }
  return product;
}
