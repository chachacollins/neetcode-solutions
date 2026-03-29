/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        
        int idx = 0;
        while(end) {
            idx++;
            end = end->next;
        }
        if(n == idx) return head->next;
        auto iter = head;
        auto prev = head;
        for(int i = 0; i < (idx-n); i++) {
            prev = iter;
            iter = iter->next;
        }
        if(iter) {
            prev->next = iter->next;
        }
        return head;
    }
};
