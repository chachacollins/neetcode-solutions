class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        int n = temp.size();
        for(int i = 0; i < n; i++) {
            int a = 0;
            for(int j = i+1; j < n; j++) {
                int sub = temp[j] - temp[i];
                if(sub > 0) {
                    a = j-i;
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
