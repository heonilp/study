class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
        int a = 0;
        ListNode *ans = l1;
		
        while (l1 || l2) 
        {
            int tmp = l1->val + (l2 ? l2->val : 0) + a;
            l1->val = tmp % 10;
            a = tmp > 9 ? 1 : 0;
			
            if (!l1->next && (a > 0 || (l2 && l2->next))) l1->next = new ListNode();
            l1 = l1->next;
            if (l2)  l2 = l2->next;
        }
        
        return ans;
    }
};