//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
class Solution {
public:
  ListNode* sortList(ListNode* head) 
  {
    if (!head || !head->next) return head;
    ListNode* f = head;
    ListNode* e = head->next;   
      
    while (e && e->next) 
    {
      e = e->next->next;
      f = f->next;
    }
      
    ListNode* node = f->next;    
    f->next = nullptr;
    return merge(sortList(head), sortList(node));
  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode node;
    ListNode* tail = &node;
      
    while (l1 && l2) 
    {
      if (l1->val > l2->val) swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
      
    tail->next = l1 ? l1 : l2;    
    return node.next;
  }
};