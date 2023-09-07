/*
  P10 数值的 n 次方

  实现一个函数，用它来计算浮点数的 n 次方。

  比如说，给你 2 和 11，你要计算出 2 的 11 次方的结果：

  pow(2, 11) = 2^11
 */

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  // T: O(logN), S: O(1)
  double myPow(double x, int n) {
    double result = 1;
    long long nAbs = abs(n);
    if (n == 0) {
      return 1.0;
    }
    while (nAbs != 0) {
      if ((nAbs & 1) == 1) {
        result *= x;
      }
      x *= x;
      nAbs >>= 1;
    }
    return n < 0 ? 1/result : result;
  }
};

int main()
{
  Solution s = Solution();
  double result = s.myPow(10, -2);
  cout << result << endl;
}
