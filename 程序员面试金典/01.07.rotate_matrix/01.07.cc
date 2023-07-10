#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void rotate(vector< vector<int> >& matrix) {
    int n = matrix.size();
    if(n == 0) { return; }
    int r = (n>>1)-1; //左上角区域的最大行下标
    int c = (n-1)>>1; //左上角区域的最大列下标
    for(int i = r; i >= 0; --i) {
      for(int j = c; j >= 0; --j) {
        swap(matrix[i][j], matrix[j][n-i-1]);
        swap(matrix[i][j], matrix[n-i-1][n-j-1]);
        swap(matrix[i][j], matrix[n-j-1][i]);
      }
    }
  }
};

void printMatrix(vector< vector<int> >& matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  Solution s = Solution();
  vector< vector<int> > matrix { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  printMatrix(matrix);
  s.rotate(matrix);
  printMatrix(matrix);
}
