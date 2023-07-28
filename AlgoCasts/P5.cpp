/*
  P5 不用+/-求两数之和

  给你两个整数，在不使用 +/- 这两个运算符的前提下，求它们的和。
 */

#include <iostream>

using namespace std;

class Solution {
public:
  // T: O(n), S: O(1)
  int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
  }
};

int main()
{
  Solution s = Solution();
  cout << s.getSum(9, 11) << endl;
}
