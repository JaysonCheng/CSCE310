#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "csce310homework04part03.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream sFile1( argv[1] );
  istream_iterator<int> sStart1(sFile1),sEnd1;
  vector<int> segments01(sStart1,sEnd1);

  ifstream sFile2( argv[2] );
  istream_iterator<int> sStart2(sFile2),sEnd2;
  vector<int> segments02(sStart2,sEnd2);

  ifstream tFile1( argv[3] );
  istream_iterator<int> tStart1(tFile1),tEnd1;
  vector<int> transitions01(tStart1,tEnd1);

  ifstream tFile2( argv[4] );
  istream_iterator<int> tStart2(tFile2),tEnd2;
  vector<int> transitions02(tStart2,tEnd2);

  try{
    cout << "The race can be completed in " << footRace( segments01 , segments02 , transitions01 , transitions02 ) << " seconds." << endl;
  }
  catch( int e ){
    cerr << "An error occurred" << endl;
  }
  
  return 0;
  }
