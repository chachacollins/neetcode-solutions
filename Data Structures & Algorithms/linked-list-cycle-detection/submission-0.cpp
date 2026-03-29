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
    bool hasCycle(ListNode* head) {
        unordered_map<int,int> m;
        int idx = 0;
        auto iter = head;
        while(iter && idx <= 1000) {
            m[iter->val] += 1;
            iter = iter->next;
            idx++;
        }
        for(auto& [k, v]: m) {
            if(v > 10) return true;
        }
        return false;
    }
};
