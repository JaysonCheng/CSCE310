#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "csce310a03part03.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream xFile( argv[1] );
  istream_iterator<int> xStart(xFile),xEnd;
  vector<int> xs(xStart,xEnd);

  ifstream yFile( argv[2] );
  istream_iterator<int> yStart(yFile),yEnd;
  vector<int> ys(yStart,yEnd);
  int result = hornerRule( xs , ys[0] );
  cout<<result;
  return 0;
}
