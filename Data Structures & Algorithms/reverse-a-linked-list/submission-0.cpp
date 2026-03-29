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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* root = head;
        ListNode* iter = head->next;
        while(iter) {
            ListNode* n = new ListNode(iter->val);
            n->next = root;
            root = n;
            iter = iter->next;
        }
        head->next = nullptr;
        return root;
    }
};
