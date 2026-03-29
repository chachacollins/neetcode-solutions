class KthLargest {
    multiset<int, greater<int>> m;
    int k;
public:
    KthLargest(int k, vector<int>& nums): k{k} {
        for(auto i: nums) m.insert(i);
    }
    //[1, 2, 3,3,3,5,6,7,8]
    int add(int val) {
        m.insert(val);
        auto cpy = m;
        int kth = 0, idx = 0;
        for(auto c: cpy) {
            if(idx == k) break;
            kth = c;
            idx++;
        }
        return kth;
    }
};
