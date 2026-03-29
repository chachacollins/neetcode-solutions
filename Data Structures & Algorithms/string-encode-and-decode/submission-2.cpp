class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto str: strs) {
            ans += to_string(str.size());
            ans += ',';
            ans += str;
        }
        return ans;
    }

    pair<string, int> read_string(string &s, int offset) {
        int i = 0;
        while (i < s.size() && isdigit(s[i+offset])) {
            i++;
        }
        int len = std::stoi(s.substr(offset, i));
        int skip = to_string(len).size() + 1;
        string ans = s.substr(offset+skip, len);
        return {ans, len + skip};
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int offset = 0;
        while((s.size() - offset) > 0) {
            auto p =  read_string(s, offset);
            ans.push_back(p.first);
            offset += p.second;
        }
        return ans;
    }
};
