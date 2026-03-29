class Solution {
    int count_ones(int n) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            if((n >> i) & 1) count++;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(count_ones(i));
        }
        return ans;
    }
};
