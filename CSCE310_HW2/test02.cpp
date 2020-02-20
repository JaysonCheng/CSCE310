#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include "csce310homework02part02.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream numberFile( argv[1] );
  istream_iterator<double> nStart(numberFile),nEnd;
  vector<double> number(nStart,nEnd);

  ifstream sumFile( argv[2] );
  istream_iterator<double> sStart(sumFile),sEnd;
  vector<double> sum(sStart,sEnd);

  try{
    bool statement = sumToN( number , sum[0] );
    if( statement ){
      cout << "There are two digits that sum to " << sum[0] << endl;
    }
    else{
      cout << "There are not two digits that sum to " << sum[0] << endl;
    }
  }
  catch( int ex ){
    cerr << "An error occurred" << endl;
  }
 
  return 0;
}
