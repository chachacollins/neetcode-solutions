class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while(stones.size() >= 2) {
            auto y = stones.back(); stones.pop_back();
            auto x = stones.back(); stones.pop_back();
            if(x <= y) {
                stones.push_back(y-x);
            }
            sort(stones.begin(), stones.end());
        }
        return stones[0];
    }
};
