

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