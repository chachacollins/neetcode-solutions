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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> ans;
        if(!list1 && !list2) return nullptr;
        auto iter1 = list1;
        auto iter2 = list2;
        while(iter1 || iter2) {
            if(iter1 && iter2) {
                ans.push_back(min(iter1->val, iter2->val));
                ans.push_back(max(iter1->val, iter2->val));
                iter1 = iter1->next;
                iter2 = iter2->next;
            } else if(iter1) {
                ans.push_back(iter1->val);
                iter1 = iter1->next;
            } else if(iter2) {
                ans.push_back(iter2->val);
                iter2 = iter2->next;
            }
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        ListNode *start = new ListNode(ans[0]);
        for(int i = 1; i < ans.size(); i++) {
            auto node = new ListNode(ans[i]);
            node->next = start;
            start = node;
        }
        return start;
    }
};


















