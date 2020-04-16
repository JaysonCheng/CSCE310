#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "csce310homework04part01.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream weightsFile( argv[1] );
  istream_iterator<int> wStart(weightsFile),wEnd;
  vector<int> weight(wStart,wEnd);

  ifstream capacitiesFile( argv[2] );
  istream_iterator<int> cStart(capacitiesFile),cEnd;
  vector<int> capacity(cStart,cEnd);

  try{
    cout << tallestTower( weight , capacity ) << " can be stacked on each other at most." << endl;
  }
  catch( int e ){
    cerr << "An error occurred" << endl;
  }
 
  return 0;
}
