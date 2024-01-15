/*
  P14 判断单链表是否为回文链表

  比如说，给你的链表是：

  4 -> 2

  它表示 42，反过来是 24，不是一个回文数字，因此你要返回 false。

  再比如说，给你的链表是：

  4 -> 2 -> 2 -> 4

  它表示 4224，反过来也是 4224，它是一个回文数字，因此你要返回 true。
 */

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // T: O(n), S: (1)
  bool isPalindrome(ListNode* head) {
    int len = 0;
    for (ListNode *p = head; p != NULL; p = p->next, ++len);

    ListNode *curr = head, *prev = NULL;

    for (int i = 0; i < len / 2; ++i) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    if (len % 2 == 1) {
      curr = curr->next;
    }
    for (; prev != NULL && curr != NULL; prev = prev->next, curr = curr->next) {
      if (prev->val != curr->val) {
	return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution s = Solution();
  ListNode l = ListNode(4, new ListNode(2, new ListNode(1)));
  cout << s.isPalindrome(&l) << endl;
}
