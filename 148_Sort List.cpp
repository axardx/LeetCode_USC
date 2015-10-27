// refer to LeetCode Discussion
// https://leetcode.com/discuss/42289/clean-and-short-merge-sort-solution-in-c
// https://leetcode.com/discuss/55446/my-recursive-and-iterative-versions-c-60ms
// not constan space

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
    ListNode* merge( ListNode* head , ListNode * head2){
        /*
         ListNode* d = new ListNode(0);
         ListNode* tmp = d;
         
         while ( head1 || head2 ) {
         if ( head1 && (!head2 || head1->val <= head2->val ) ) {
         tmp->next = head1;
         tmp = tmp->next;
         head1 = head1->next;
         }
         if ( head2 && (!head1 || head2->val < head1->val ) ) {
         tmp->next = head2;
         tmp = tmp->next;
         head2 = head2->next;
         }
         }
         tmp->next = NULL;
         return d->next;
         */
        
        ListNode* head1 = head;
        
        while ( head2 ) {
            
            if ( head2->val < head->val ) {
                ListNode* tmp = head2;
                head2 = head2->next;
                tmp->next = head;
                head = tmp;
                head1 = head;
                
            }
            
            else if ( head1->next && head1->next->val <= head2->val )
                head1 = head1->next;
            else {
                
                if ( head1->next ) {
                    ListNode* tmp = head2;
                    head2 = head2->next;
                    tmp->next = head1->next;
                    head1->next = tmp;
                    
                    head1 = head1->next;
                }
                else {
                    head1->next = head2;
                    break;
                }
            }
        }
        return head;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if ( !head || !head->next )
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while ( fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head_right = slow->next;
        slow->next = NULL;
        
        return merge( sortList(head), sortList(head_right) );
    }
};