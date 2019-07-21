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
        ListNode* reverseList(ListNode* head) {
            if(head == NULL) return NULL;           // Empty list
            if(head->next == NULL) return head;     // Size = 1

            ListNode* res;
            ListNode* trail = head;
            /* Iterate through, store curr location, update iterator before
            pointers are overwritten, flip next to trailing pointer, update trail */
            for(ListNode* t = head->next; t != NULL;) {
                res = t;
                t = t->next;
                res->next = trail;
                trail = res;
            }
            head->next = NULL;                      // Flip original start, to end

            return res;
        }
    };