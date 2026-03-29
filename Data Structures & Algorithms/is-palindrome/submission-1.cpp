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
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (r > l && !isalnum(s[r])) {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
