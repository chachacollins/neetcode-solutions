class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> temp;
       for(const auto &s: strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        temp[sorted].push_back(s);
       }
       vector<vector<string>> ans;
       for(auto &pair: temp) {
        ans.push_back(pair.second);
       }
       return ans;
    }
};
