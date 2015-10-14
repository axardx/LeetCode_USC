
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if ( l1 == NULL )
            return l2;
        else if ( l2 == NULL )
            return l1;
        else if ( l1 == NULL && l2 == NULL )
            return l1;
        
        int sum = 0, carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;
        
        while ( l1 != NULL || l2 != NULL || carry ) {
            
            sum = 0;
            
            if ( l1 && l2 )
                sum = l1->val + l2->val + carry;
            else if ( !l1 && l2 )
                sum = l2->val + carry;
            else if ( l1 && !l2 )
                sum = l1->val + carry;
            else if ( !l1 && !l2 )
                sum = carry;
            
            carry = 0;
            
            if ( sum >= 10 ) {
                carry = sum / 10;
                sum %= 10;
            }
            tmp->next = new ListNode(sum);
            tmp = tmp -> next;
            
            if ( l1 != NULL )
                l1 = l1->next;
            if ( l2 != NULL )
                l2 = l2->next;
            
        }
        return ans->next;
    }
};