// refer to https://leetcode.com/discuss/62718/c-392ms-beats-99-95%25-persons
//

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
    
    ListNode* merge( ListNode* l1, ListNode* l2) {
        
        ListNode* d = new ListNode(0);
        ListNode* tmp = d;
        
        while ( l1 && l2 ) {
            if ( l2 == NULL || l1->val <= l2->val ) {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else if ( l1 == NULL || l2->val < l1->val ) {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        tmp->next = l1==NULL ? l2 : l1;
        return d->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if ( lists.size() == 0 )
            return NULL;
        
        int gap = 2;
        int n = lists.size();
        
        while ( n > 1 ) {
            
            for ( int j = 0; j < lists.size(); j += gap ) {
                if ( j + gap/2 < lists.size() ) {
                    ListNode* tmp = merge( lists[j], lists[j+gap/2] );
                    lists[j] = tmp;
                    n--;
                }
            }
            gap *= 2;
        }
        return lists[0];
    }
};