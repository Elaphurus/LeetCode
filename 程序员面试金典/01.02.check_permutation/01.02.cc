#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        unordered_map<char, int> dic;
        for (char c : s1) {
            dic[c] += 1;
        }
        for (char c : s2) {
            dic[c] -= 1;
        }
        for (auto kv : dic) {
            // cout << kv.first << ":" << kv.second << endl;
            if (kv.second != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s = Solution();
    cout << s.checkPermutation("abc", "bac") << endl;
    cout << s.checkPermutation("abc", "bad") << endl;
    return 0;
}
