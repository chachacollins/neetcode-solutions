class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        for(int i = 0; i < s2.size(); i++) {
            auto s3 = s2.substr(i, s1.size());
            sort(s3.begin(), s3.end());
            if(s1 == s3) return true;
        }
        return false;
    }
};
