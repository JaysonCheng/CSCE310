#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include "csce310homework02part03.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream numberFile( argv[1] );
  istream_iterator<int> nStart(numberFile),nEnd;
  vector<int> number(nStart,nEnd);

  

  try{
    double averageCom = averageComparisons( number );
    
      cout << "The average number of comparisons is " << averageCom << endl;
    
  }
  catch( int ex ){
    cerr << "An error occurred" << endl;
  }
 
  return 0;
}
