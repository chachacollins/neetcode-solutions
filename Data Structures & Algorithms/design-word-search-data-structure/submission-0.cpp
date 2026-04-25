struct TrieNode {
    bool isWord;
    array<TrieNode*, 26> children{};
    TrieNode() {}
};

TrieNode* createNode() { return new TrieNode(); }

class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { root = createNode(); }

    void addWord(string word) {
        auto iter = root;
        for (auto c : word) {
            auto w = &iter->children[c - 'a'];
            if (*w == nullptr) {
                *w = createNode();
            }
            iter = *w;
        }
        iter->isWord = true;
    }
    bool dfs(int j, TrieNode* curr, string word) {
        auto iter = curr;
        for (int i = j; i < word.size(); i++) {
            auto c = word[i];
            if (c == '.') {
                for (auto child: iter->children) {
                       if(child && dfs(i+1, child, word)) return true;
                }
                return false;
            } else {
                auto w = iter->children[c - 'a'];
                if (w == nullptr) {
                    return false;
                }
                iter = w;
            }
        }
        return iter->isWord;
    }
    bool search(string word) {
        return dfs(0, root, word);
    }
};
