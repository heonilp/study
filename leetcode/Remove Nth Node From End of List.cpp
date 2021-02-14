//Follow up: Could you do this in one pass?
//상도쿤의 one pass 채찍...? 다시 풀었어요.
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      ListNode* dummyNode = new ListNode();
      dummyNode->next = head;
      
      int len = 0;
      ListNode * node = head;
      
      while(node != nullptr)
      {
          ++len;
          node = node->next;
      }
      
      len = len - n;
      node = dummyNode;
      
      while(len--)
      {
          node = node->next;
      }
      
      node->next = node->next->next;
      
      return dummyNode->next;
  }
};

//2pass방식이라네요.
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        ListNode* s=head;
        ListNode* f=head;
        ListNode* p=head;
        
        for(int i=0;i<n;i++) f=f->next;
        
        if(f==nullptr) return head->next;
        
        while(f!=nullptr)
        {
            p=s;
            s=s->next; 
            f=f->next;
        }
        
        p->next=s->next;  
        return head;
  }
};