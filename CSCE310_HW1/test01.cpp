#include "csce310homework01part01.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  ifstream numberFile( argv[1] );
  istream_iterator<unsigned long long int> nStart(numberFile),nEnd;
  vector<unsigned long long int> number(nStart,nEnd);
  
  printf( "%llu has a sum of %llu\n" , number[0] , productOfDigits( number[0] ) );
}
