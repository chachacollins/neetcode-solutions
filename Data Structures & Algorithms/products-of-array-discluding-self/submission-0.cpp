class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int> ans(n);
        int num = 1;
       for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            num *= nums[j];
            ans[i] = num;
        }
        num = 1;
       }
       return ans;
    }
};
