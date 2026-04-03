#include <cstring>
class PrefixTree {
    vector<string> words;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        words.emplace_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
        char c = word[0];
        for(auto& s: words) {
            if(s[0] == c && s.size() == n) {
                if(!memcmp(s.c_str()+1, word.c_str()+1, n-1)) return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        size_t n = prefix.size();
        for(auto& s: words) {
            if(!memcmp(prefix.c_str(), s.c_str(), n)) return true;
        }
        return false;
    }
};
