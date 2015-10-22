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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL || head->next == NULL )
            return head;
        else if ( head->val == head->next->val && head->next->next == NULL )
            return NULL;
        
        
        ListNode* cur = head->next;
        ListNode* prev = head;
        
        while ( cur!= NULL ) {
            bool duplicate = false;
            
            // if the first sequence of nodes are the same
            while ( prev->val == cur->val ) {
                cur = cur->next;
                if ( cur == NULL )
                    return NULL;
                duplicate = true;
            }
            if ( duplicate ) {
                if ( prev == head ) {
                    head = cur;
                    prev = cur;
                    cur = cur->next;
                    if ( cur == NULL )
                        break;
                    continue;
                }
            }
            
            while ( cur->next != NULL && cur->val == cur->next->val ) {
                cur = cur->next;
                duplicate = true;
            }
            if ( duplicate ) {
                prev->next = cur->next;
                cur = cur->next;
            }
            
            else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return head;
    }
};