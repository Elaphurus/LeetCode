/*
  P2 求和为给定值的两个数

  给你一个整数数组和一个目标值，你要找到数组里两个整数，它们的和等于目标值。
  然后返回这两个整数的下标。

  比如说给你的整数数组是：
    1, 2, 3, 6, 8, 11
  目标值是 10。那么，满足条件的两个整数是，2 和 8，它们的和是 10。
  所以你要返回它们的下标是 1 和 4。
 */

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
  // T: O(n^2), S: O(1)
  vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          result[0] = i;
          result[1] = j;
          return result;
        }
      }
    }
    return result;
  }

  // T: O(n), S: O(n)
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    map<int, int> hashTab;
    for (int i = 0; i < nums.size(); ++i) {
      int numNeed = target - nums[i];
      if (hashTab.count(numNeed) > 0) {
        result[0] = hashTab[numNeed];
        result[1] = i;
        return result;
      }
      hashTab[nums[i]] = i;
    }
    return result;
  }
};

int main()
{
  Solution s = Solution();
  vector<int> nums = {1, 2, 3, 6, 8, 11};
  vector<int> result;

  result = s.twoSumBruteForce(nums, 10);
  cout << result[0] << "," << result[1] << endl;

  result = s.twoSum(nums, 10);
  cout << result[0] << "," << result[1] << endl;
}
