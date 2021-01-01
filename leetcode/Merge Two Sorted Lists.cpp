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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* head = new ListNode();
		ListNode* pnode = head;

		while (l1 != NULL && l2 != NULL) 
        {
			if (l1->val <= l2->val)
            {
				pnode->next = l1;
				l1 = l1->next;
			}
			else {
				pnode->next = l2;
				l2 = l2->next;
			}
			pnode = pnode->next;
		}

		if (l1 != NULL) 
        {
			pnode->next = l1;
		}
		else if (l2 != NULL)
        {
			pnode->next = l2;
		}

		return head->next;
	}
};