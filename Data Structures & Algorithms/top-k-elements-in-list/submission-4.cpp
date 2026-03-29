class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<pair<int, int>> f;
        for(auto num: nums) {
            m[num] += 1;
        }
        for(auto &pair: m) {
            f.push_back({pair.second, pair.first});
        }
        sort(f.begin(), f.end());
        reverse(f.begin(), f.end());
        int idx = 0;
        vector<int> ans;
        for(auto &pair: f) {
            if(idx == k) break;
            ans.push_back(pair.second);
            idx++;
        }
        return ans;
    }
};
