/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   bool hasCycle(ListNode *head) {
      while (head) 
      {
          if (head == head->next) return true;
          ListNode *_node = head->next;
          head->next = head;
          head = _node;
      }
      return false;
}
};