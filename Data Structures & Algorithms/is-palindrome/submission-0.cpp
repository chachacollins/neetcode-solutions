class Solution {
public:
    string str_tolower(string &s) {
        string n;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isalnum(c)) {
                n.push_back(tolower(c));
            }
        }
        return n;
    }
    bool isPalindrome(string s) {
        s = str_tolower(s);
        string ns = s;
        reverse(ns.begin(), ns.end());
        return ns == s;
    }
};
