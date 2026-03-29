class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            vector<string> temp{s};
            for(int j = i+1; j < strs.size(); ++j) {
                string t = strs[j];
                if(isAnagram(s, t)) {
                    temp.emplace_back(t);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
