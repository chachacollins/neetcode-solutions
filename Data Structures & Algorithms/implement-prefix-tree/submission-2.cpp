
struct TrieNode {
    bool isWord;
    array<TrieNode*, 26> children{};
    TrieNode() {}
};

TrieNode *createNode() {
    return new TrieNode();
}

inline int getIdx(char c) {
    return c - 'a';
}

class PrefixTree {
    TrieNode *root;
public:
    PrefixTree() {
        root = createNode();
    }
    
    void insert(string word) {
        auto iter = root;
        for (auto &c: word) {
            auto w = &iter->children[getIdx(c)];
            if (*w == nullptr) {
                *w = createNode();
            }
            iter = *w;
        }
        iter->isWord = true;
    }
    
    bool search(string word) {
        auto iter = root;
        for (auto &c: word) {
            auto w = &iter->children[getIdx(c)];
            if (*w == nullptr) {
               return false;
            }
            iter = *w;
        }
        return iter->isWord;
    }
    
    bool startsWith(string prefix) {
        auto iter = root;
        for (auto &c: prefix) {
            auto w = &iter->children[getIdx(c)];
            if (*w == nullptr) {
               return false;
            }
            iter = *w;
        }
        return true;
    }
};
