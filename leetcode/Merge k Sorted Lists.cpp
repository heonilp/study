/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
		ListNode* node = new ListNode(0);
		ListNode *p = node;
        
		while (1) {
			int m = -1;
			for (int i = 0; i < lists.size(); i++)
            {
				if (lists[i] != nullptr) 
                {
					m = i;
					break;
				}
            }
            
			if (m == -1)
            {
                break;
            } 
			for (int i = 0; i < lists.size(); i++)
            {
				if (lists[i] != nullptr)
                {
					if (lists[i]->val < lists[m]->val)
                    {
                         m = i;
                    };
                }
            }

			node->next = lists[m];
			node = node->next;
			lists[m] = lists[m]->next;
		}
		return p->next;
	}
};