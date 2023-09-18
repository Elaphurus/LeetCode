/*
  P11 数组的全排列

  给你一个整数数组，并且数组中没有重复元素，你要返回这个数组所有可能的排列。

  比如说给你的数组是：

  0, 1, 2

  你要返回的所有排列是：

  0, 1, 2
  0, 2, 1
  1, 0, 2
  1, 2, 0
  2, 0, 1
  2, 1, 0
*/

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
private:
  void permuteRec(vector<int>& nums, int start, vector<vector<int>>& result)
  {
    if (start == nums.size()) {
      result.emplace_back(nums);
    } else {
      for (int i = start; i < nums.size(); ++i) {
        swap(nums[i], nums[start]);
        permuteRec(nums, start + 1, result);
        swap(nums[start], nums[i]);
      }
    }
  }
public:
  // T: O(n*n!), S: O(n)
  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> *result = new vector<vector<int>>;
    if (nums.size() == 0) {
      return *result;
    }
    permuteRec(nums, 0, *result);
    return *result;
  }
};

int main()
{
  Solution s = Solution();
  vector<int> nums = {0, 1, 2};
  vector<vector<int>> result = s.permute(nums);

  for (vector<int> p : result) {
    for (int i : p) {
      cout << i << " ";
    }
    cout << endl;
  }
}
