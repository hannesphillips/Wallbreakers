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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;             // Size < 2
        if(k == 1) return head;                                         // Edge case
        
        ListNode* trail = head;
        ListNode* k_tail;
        ListNode* k_t;
        ListNode* l_tail;
        
        int x = k - 2;
        bool first_rev = true;
        /* Iterate through list, begin reversal after encountering k nodes.
        Reverse as normal, store tail of current to section to link to head of
        next group if reversal is performed. Reset counter and continue. */
        for(ListNode* t = head->next; t != NULL;) {
            if(x == 0) {
                t = t->next;
                k_tail = trail;
                // Reverse here
                for(ListNode* z = trail->next; z != t;) {
                    k_t = z;
                    z = z->next;
                    k_t->next = trail;
                    trail = k_t;
                }
                k_tail->next = t;
                trail = t;
                x = k;
                
                // Update head or link prev tail to next reversed group
                if(first_rev) {
                    head = k_t;
                    first_rev = false;
                }
                else
                    l_tail->next = k_t;
                l_tail = k_tail;
            }
            else
                t = t->next;
            
            x--;
        }
        return head;
    }
};