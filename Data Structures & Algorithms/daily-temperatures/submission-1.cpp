class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        vector<pair<int, int>> stack;
        for(int i = 0; i < n; i++) {
          int t = temp[i];
          while(stack.size() && t > stack.back().second) {
            auto [si, st] = stack.back(); stack.pop_back();
            ans[si] = (i - si);
          }
          stack.push_back({i, t});
        }
        return ans;
    }
};
