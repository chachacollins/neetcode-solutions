class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> s;
        int n = prices.size();
        if(n < 2) return 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int sub = prices[j] - prices[i];
                s.push_back(sub);
            }
        }
        sort(s.begin(), s.end());
        int last = s[s.size()-1];
        if(last > 0) return last; 
        return 0;
    }
};
