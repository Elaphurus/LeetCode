#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int bits = 0;
        for (int i = 0; i < astr.size(); i++) {
            int bit = 1 << (astr[i] - 'a');
            // cout << bits << "&" << bit << "=" << (bits & bit) << endl;
            if (bits & bit) {
                return false;
            }
            bits |= bit;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    cout << s.isUnique("abc") << endl;
    cout << s.isUnique("aba") << endl;
    return 0;
}
