/*
  P9 反转单链表

  给你一个单链表，你需要反转它，然后返回。

  比如说给你的单链表是：

  1 -> 2 -> 3 -> 4 -> 5 -> null

  你要返回的反转后的链表是：

  5 -> 4 -> 3 -> 2 -> 1 -> null
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
  // T: O(n), S: O(1)
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head, *pre = NULL;
    while (cur != NULL) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};

void printListNode(ListNode *l)
{
  while (l != NULL) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  Solution s = Solution();

  ListNode l = ListNode(1, new ListNode(2, new ListNode(3)));

  printListNode(&l);

  printListNode(s.reverseList(&l));
}
