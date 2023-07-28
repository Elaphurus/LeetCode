/*
  P4 判断二叉树是否对称

  给你一个二叉树，你要判断它是否沿中轴线对称。

  比如说，给你的二叉树是：

       1
     /   \
    2     2
   / \   / \
  4   8 8   4

  这棵二叉树是沿中轴线对称的，因此要返回 true。

  如果我去掉最后这个 4：

       1
     /   \
    2     2
   / \   /
  4   8 8

  就不对称了，这时就要返回 false。
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  bool isEqual(TreeNode* t1, TreeNode* t2) {
    if (t1 != NULL && t2 != NULL)
      return t1->val == t2->val
        && isEqual(t1->left, t2->right) && isEqual(t1->right, t2->left);
    else
      return t1 == NULL && t2 == NULL;
  }
public:
  // T; O(n), S: O(n)
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    else
      return isEqual(root->left, root->right);
  }
};

int main()
{
  Solution s = Solution();

  TreeNode root = TreeNode(1,
    new TreeNode(2, new TreeNode(4), new TreeNode(8)),
    new TreeNode(2, new TreeNode(8), new TreeNode(4)));

  cout << s.isSymmetric(&root) << endl;
}
