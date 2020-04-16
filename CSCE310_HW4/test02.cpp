#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "csce310homework04part02.h"
using namespace std;

int main(int argc , char* argv[]){
  
  vector<int> weight;
  int w;
  
  while( cin >> w ){
    weight.push_back( w );
  }
  
  try{
    cout << "The teams are " << tugOfWar( weight ) << " pounds apart." << endl;
  }
  catch( int e ){
    cerr << "An error occurred" << endl;
  }
 
  return 0;
}
