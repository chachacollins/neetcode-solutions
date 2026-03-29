class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int b = 0; b < (1 << n); b++) {
            vector<int> sub;
            for(int i = 0; i < n; i++) {
                if(b & (1 << i)) sub.emplace_back(nums[i]);
            }
            ans.emplace_back(sub);
        }
        return ans;
    }
};
