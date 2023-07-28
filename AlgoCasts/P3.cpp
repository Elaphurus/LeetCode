/*
  P3 有序数组中求和为给定值的两个数

  给你一个整数数组，并且这个数组是按递增排序的，你要找到数组中的两个整数，
  它们的和等于给定的目标值，然后返回它们的下标。
  题目假设给你的数组总是有且只有一个解，而且同一个元素不能使用两次。
  另外，返回结果的下标要从 1 开始。

  比如说给你的整数数组是：
    1, 2, 3, 6, 8, 11
  目标值是 10。那么，满足条件的两个整数是，2 和 8，它们的和是 10。
  所以你要返回它们的下标是 2 和 5。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  // T: O(n), S: O(1)
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    int i = 0, j = nums.size() -1;
    while (i < j) {
      if (nums[i] + nums[j] > target)
        --j;
      else if (nums[i] + nums[j] < target)
        ++i;
      else {
        result[0] = i + 1;
        result[1] = j + 1;
        return result;
      }
    }
    return result;
  }
};

int main()
{
  Solution s = Solution();
  vector<int> nums = {1, 2, 3, 6, 8, 11};
  vector<int> result;

  result = s.twoSum(nums, 10);
  cout << result[0] << "," << result[1] << endl;
}
