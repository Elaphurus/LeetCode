/*
  P8 判断二叉树是否相同

  给你两个二叉树，你要判断它们是否相同。
  这里所谓相同，指的是两棵树结构相同，并且相应节点上的数值相等。

  比如说，给你的两棵二叉树是：

    1          1
   / \        / \
  2   4      2   4

  它们的结构相同，相应节点上的值也相等，因此返回 true。 如果另一棵树是：

    1
   / \
  2   5

  或

      1
     /
    2
   /
  4


  两棵树则不相同，返回 false。
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
public:
  // T; O(n), S: O(n)
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
      return true;
    if (p == NULL || q == NULL)
      return false;
    return p->val == q->val
      && isSameTree(p->left, q->left)
      && isSameTree(p->right, q->right);
  }
};

int main()
{
  Solution s = Solution();

  TreeNode p = TreeNode(1, new TreeNode(2), new TreeNode(4));
  TreeNode q = TreeNode(1, new TreeNode(2, new TreeNode(4), NULL), NULL);

  cout << s.isSameTree(&p, &q) << endl;
}
