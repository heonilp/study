//138. Copy List with Random Pointer


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* it = head;
        
        while(it)
        {
            Node* node = new Node(it->val);
            node->next = it->next;
            it->next = node;
            it = it->next->next;
        }
        
        it = head;
        
        while(it) 
        {
            if(it->random)
            {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }
        
        Node* ans = head->next;
        it = head;
        Node* temp = ans;
        
        while(temp->next)
        {
            it->next = it->next->next;
            it = it->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        it->next = nullptr;
        
        return ans;
    }
};