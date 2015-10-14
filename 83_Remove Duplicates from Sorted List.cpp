
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
        ListNode* node = head;
        while( node != NULL ) {
            if ( node->next != NULL &&  node->val == (node->next)->val ) {
                ListNode* tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            }
            else
                node = node->next;
        }
        return head;
    }
};