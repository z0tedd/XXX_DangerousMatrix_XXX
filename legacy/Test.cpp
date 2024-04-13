#include "DangerousMatrix.h"
#include <iostream>

using namespace  std;

int main(){
  vector<vector<int>> m(vector<int>(1,2),2);
DM::Matrix<int> matrix(m);
  matrix.drawMatrix();
   cout << matrix;

  return 0;
}
