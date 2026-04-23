class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        constexpr int n = 26;
        array<int, n> s1Count{};
        array<int, n> s2Count{};
        for(int i = 0; i < s1.size(); i++) {
            int sidx = s1[i] - 'a';
            int idx = s2[i] - 'a';
            s1Count[sidx] += 1;
            s2Count[idx] += 1;
        }
        int matches = 0;
        for(int i = 0; i < n; i++) {
            if (s1Count[i] == s2Count[i]) matches+=1;
        }
        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++) {
            if (matches == n) return true;
            int idx = s2[r] - 'a';
            s2Count[idx] += 1;
            if(s2Count[idx] == s1Count[idx]) matches+=1;
            else if(s2Count[idx] == s1Count[idx]+1) matches-=1;

            int i = s2[l] - 'a';
            s2Count[i] -= 1;
            if(s2Count[i] == s1Count[i]) matches+=1;
            else if(s2Count[i] == s1Count[i]-1) matches-=1;
            l++;

        }
        return matches == n;
    }
};
