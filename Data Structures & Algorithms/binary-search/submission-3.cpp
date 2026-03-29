class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t a = 0;
        size_t b = nums.size();
        while(a < b) {
            size_t m = (b + a) / 2;
            int k = nums[m];
            if(k == target) return m;
            if(k > target) {
                b = m;
            } else {
                a = m + 1;
            }
        }
        return -1;
    }
};
