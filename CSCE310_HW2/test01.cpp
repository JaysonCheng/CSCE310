/*
  Name: Jayson Cheng
  NUID: 28638995
  CSCE 310 Assignment 2
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "csce310homework02part01.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream startFile( argv[1] );
  istream_iterator<double> sStart(startFile),sEnd;
  vector<double> numberStart(sStart,sEnd);

  ifstream endFile( argv[2] );
  istream_iterator<double> eStart(endFile),eEnd;
  vector<double> numberEnd(eStart,eEnd);

  try{
    cout << "There are " << overlappingIntervals( numberStart , numberEnd ) << " overlapping intervals." << endl;
  }
  catch( int ex ){
    cerr << "An error occurred" << endl;
  }
 
  return 0;
}
