class Solution {
public:
    ListNode * root;
    void go(ListNode *node1,ListNode *node2)
    {
        if(node1==nullptr)
        {
            root=node2;
            return ;
        }
        go(node1->next,node1);
        node1->next=node2;
    }
    
    
    bool isPalindrome(ListNode* head)
    {
        ListNode *node1 = nullptr;
        ListNode *node2 = nullptr;
        ListNode *temp=head;
        node1=node2=head;
        
        while(node1 && node1->next)
        {
            node1=node1->next->next;
            node2=node2->next;
        }
        go(node2,nullptr);
        
        while(root)
        {
            if(temp->val!=root->val) return false;
            
            root=root->next;
            temp=temp->next;
        }
        return true;
    }
};