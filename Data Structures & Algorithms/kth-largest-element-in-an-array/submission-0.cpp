class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> s;
        for(auto c: nums) {
            s.insert(c);
        }
        int idx = 0;
        int a = 0;
        for(auto x: s) {
            if(idx == k) break;
            idx++;
            a = x;
        }
        return a;
    }
};
