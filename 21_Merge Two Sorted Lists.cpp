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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if ( l1 == NULL )
            return l2;
        else if ( l2 == NULL)
            return l1;
        
        ListNode* ans = l1->val < l2->val ? l1:l2;
        ListNode* tmp = ans;
        if ( ans == l1 ) {
            l1 = l1->next;
        }
        else {
            l2 = l2->next;
        }
        
        while ( l1 != NULL && l2 != NULL ) {
            if ( l1->val <= l2->val ) {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        
        while ( l1 != NULL ) {
            tmp -> next = l1;
            l1 = l1->next;
            tmp = tmp->next;
        }
        
        while ( l2 != NULL ) {
            tmp -> next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
        
        return ans;
    }
};