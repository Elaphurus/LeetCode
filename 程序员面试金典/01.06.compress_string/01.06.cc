#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string compressString(string S) {
    string ret = "";
    char lastCh = S[0];
    ret += lastCh;
    int pos = 1;
    int length = 1;
    for (int i = 1; i < S.size(); i++) {
      if (S[i] == lastCh) {
        length++;
      } else {
        ret += to_string(length);
        length = 1;
        lastCh = S[i];
        ret += lastCh;
      }
    }
    ret += to_string(length);

    if (ret.size() < S.size()) {
      return ret;
    } else {
      return S;
    }
  }
};

int main() {
  Solution s = Solution();
  cout << s.compressString("aabcccccaaa") << endl;
  cout << s.compressString("abbccd") << endl;
  cout << s.compressString("ccc") << endl;
  cout << s.compressString("cd") << endl;
}
