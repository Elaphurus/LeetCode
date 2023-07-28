/*
  P6 单身数字

  给你一个非空的整数数组，这个数组中有一个整数只出现了一次，其它的整数都出现两次，
  你要找出这个只出现一次的整数。

  比如说，给你的数组是：
    5, 7, 5, 6, 6
  这里 7 只出现了一次，因此你要返回的就是 7。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // T: O(n), S: O(1)
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      result ^= nums[i];
    }
    return result;
  }
};

int main()
{
  Solution s = Solution();
  vector<int> nums = {5, 7, 5, 6, 6};
  cout << s.singleNumber(nums) << endl;
}
