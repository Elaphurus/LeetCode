#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dic;
        for (char c : s) {
            dic[c] += 1;
        }
        int odd = 0;
        for (auto kv : dic) {
            if (kv.second % 2 != 0) {
                odd += 1;
            }
        }
        if (odd == 0 || odd == 1) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    cout << s.canPermutePalindrome("tacatcoa") << endl;
    return 0;
}
