/*
  P13 回文数字判断

  给你一个整数，你要判断它是否是一个回文数字。
  所谓回文数字就是，你正着读和反着读都是同一个数字。

  比如，给你的数字是：

  12321

  无论你从左向右读，还是从右向左读，都是 12321，所以它是一个回文数字，你要返回 true。

  再比如说：

  -232

  你从左向右读是 -232，但从右向左读则是 232-，和 -232 不一样，
  因此它不是一个回文数字，你要返回 false。
 */

#include <iostream>

using namespace std;

class Solution {
public:
  // T: O(n), S: O(1)
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int tmp = x;
    long y = 0;
    while (tmp != 0) {
      int num = tmp % 10;
      y = y * 10 + num;
      tmp = tmp / 10;
    }
    return y == x;
  }
};

int main()
{
  Solution s = Solution();
  cout << s.isPalindrome(1232) << endl;
}
