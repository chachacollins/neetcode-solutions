class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> v;
        for(int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if(m.find(x) != m.end()) {
                if(m[x] < i) {
                    v.emplace_back(m[x]);
                    v.emplace_back(i);
                } else {
                    v.emplace_back(i);
                    v.emplace_back(m[x]); 
                } 
                break;
            } else {
                m[nums[i]] = i;
            }
        }
        return v;
    }
};
