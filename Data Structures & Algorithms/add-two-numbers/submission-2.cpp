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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        vector<int> ans;
        auto iter1 = l1;
        auto iter2 = l2;
        while(iter1 || iter2) {
            if(iter1 && iter2) {
            int val = iter1->val + iter2->val + overflow;
            ans.push_back(val % 10);
            overflow = val / 10;
            iter1 = iter1->next;
            iter2 = iter2->next;
            } else if(iter1) {
                int val = iter1->val + overflow;
                ans.push_back(val % 10);
                overflow = val / 10;
                iter1 = iter1->next;
            } else if(iter2) {
                int val = iter2->val + overflow;
                ans.push_back(val % 10);
                overflow = val / 10;
                iter2 = iter2->next;
            }
        }
        if(overflow > 0) ans.push_back(overflow);
        reverse(ans.begin(), ans.end());
        auto al = new ListNode(ans[0]);
        for(int i = 1; i < ans.size(); i++) {
            auto nn = new ListNode(ans[i]);
            nn->next = al;
            al = nn;
        }
        return al;
    }
};
