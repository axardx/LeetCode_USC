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
    ListNode* insertionSortList(ListNode* head) {
        
        if ( head == NULL || head->next == NULL )
            return head;
        
        ListNode* cur = head->next;
        ListNode* pre = head;
        
        while( cur != NULL ) {
            
            ListNode* tmp = head;
            
            while ( tmp->next != NULL && ( tmp->next->val < cur->val ) ) {
                tmp = tmp->next;
            }
            
            while ( tmp->next != NULL && (tmp->next->val == cur->val) && (pre->val != tmp->val) ) {
                tmp = tmp->next;
            }
            
            if ( tmp == head && tmp->val > cur->val ) {
                pre->next = cur->next;
                cur->next = tmp;
                head = cur;
                
                cur = pre->next;
            }
            
            else if ( tmp->next != NULL && cur != NULL  ) {
                
                if ( tmp->next->val != cur->val ) {
                    pre->next = cur->next;
                    cur->next = tmp->next;
                    tmp->next = cur;
                    
                    cur = pre->next;
                    
                    if ( cur == NULL )
                        break;
                }
                else {
                    pre = pre->next;
                    cur = cur->next;
                }
            }
            
            if ( cur == NULL )
                break;
            
        }
        return head;
    }
};