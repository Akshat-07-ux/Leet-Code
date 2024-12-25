class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root;

    bool searchHelper(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            // If the character is '.', check all possible paths
            for (auto& child : node->children) {
                if (searchHelper(word, index + 1, child.second)) {
                    return true;
                }
            }
            return false;
        } else {
            // If the character is a specific letter, continue on that path
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[ch]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */