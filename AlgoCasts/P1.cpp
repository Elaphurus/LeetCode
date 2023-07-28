/*
 * P1 回文字符串判断
 *
 * 给你一个字符串，你要判断它是否是回文字符串。
 * 字符串里只考虑字母和数字，其它的字符可以无视。另外，对于字母，可以忽略大小写。
 *
 * 比如说，给你的字符串是："race a E-car"
 * 只考虑字母数字并且忽略大小写，它是一个回文字符串，因此返回 true。
 * 再比如说，给你的字符串是："race a car"
 * 对比到最后，中间的 e 和 a 不相等，因此不是一个回文字符串，返回 false。
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
  bool isLetterOrNumber(char c) {
    return (c >= 'a' && c <= 'z')
      || (c >= 'A' && c <= 'Z')
      || (c >= '0' && c <= '9');
  }
  bool isEqualIgnoreCase(char a, char b) {
    if (a >= 'A' && a <= 'Z')
      a += 32;
    if (b >= 'A' && b <= 'Z')
      b += 32;
    return a==b;
  }
public:
  // T: O(n), S: O(1)
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    if (s.size() == 0)
      return true;
    for (; i < j; ++i, --j) {
      while (i < j && !isLetterOrNumber(s[i]))
        ++i;
      while (i < j && !isLetterOrNumber(s[j]))
        --j;
      if (i < j && !isEqualIgnoreCase(s[i], s[j]))
        return false;
    }
    return true;
  }
};

int main() {
  Solution s = Solution();
  cout << s.isPalindrome("0P") << endl;
}
