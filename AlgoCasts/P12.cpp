/*
  P12 回文子串个数

  给你一个字符串，你要计算出它所包含的回文子串个数。
  只要起始下标或终止下标不同，即使子串相同，我们也认为是不同的回文子串。

  比如说，给你的字符串是：

  abc

  这个字符串中总共有 3 个回文子串，分别是 a， b 和 c。因此你要返回的个数是 3。

  再比如说，给你的字符串是：

  aba

  这个字符串中总共有 4 个回文子串，分别是 a，b，a，和 aba。因此你要返回的个数是 4。
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // T: O(n^2), S: O(n^2)
  int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    vector<vector<bool>> d(n, vector<bool>(n, false));
    if (n == 0)
      return 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (i == j)
          d[i][j] = true;
        else if (i + 1 == j)
          d[i][j] = s[i] == s[j];
        else
          d[i][j] = s[i] == s[j] && d[i+1][j-1];
        if (d[i][j])
          ++count;
      }
    }
    return count;
  }
};

int main() {
  Solution s = Solution();
  cout << s.countSubstrings("aaaaa") << endl;
}
