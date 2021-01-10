class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> s;
        while (headA != NULL)
        {
            s.insert(headA);
            headA = headA->next;
        }
        
        while (headB != NULL)
        {
            if (s.count(headB) == 1)
            {
                return headB;
                
            }
            headB = headB->next;
        }
        return NULL;       
    }
};