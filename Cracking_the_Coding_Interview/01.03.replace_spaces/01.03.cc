#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        stringstream ss;
        for (int i = 0; i < length; i++) {
            if (S[i] != ' ') {
                ss << S[i];
            } else {
                ss << "%20";
            }
        }
        return ss.str();
    }
};

int main() {
    Solution s = Solution();
    cout << s.replaceSpaces("Mr John Smith", 13) << endl;
    cout << s.replaceSpaces("     ", 5) << endl;
    return 0;
}
