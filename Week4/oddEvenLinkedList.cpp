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
    ListNode* oddEvenList(ListNode* head) {
        // Size <= 2
        if(head == NULL || head->next == NULL || head->next->next == NULL) 
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_first = even;
        
        // Alternate odd/even iterators through list
        for(int i = 0; odd->next != NULL && even->next != NULL; i++) {
            if(!(i%2)) {
                odd->next = odd->next->next;
                odd = odd->next;
            }
            else {
                even->next = even->next->next;
                even = even->next;
            }
        }
        // Link end of odd to beginning of even and end even w/ NULL
        even->next = NULL;
        odd->next = even_first;
        
        return head;
        
    }
};