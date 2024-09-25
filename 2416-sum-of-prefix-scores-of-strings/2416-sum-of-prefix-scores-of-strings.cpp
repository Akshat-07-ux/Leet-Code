class Solution {
   struct TrieNode {
        TrieNode* children[26] = {};
        int freq = 0;  // To store the frequency of how many words share this prefix
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string& word) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                node->freq++;  // Every time we pass through a node, we increment its frequency
            }
        }
        
        int getPrefixScore(const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char ch : word) {
                int idx = ch - 'a';
                node = node->children[idx];
                score += node->freq;  // Add the frequency at the current node
            }
            return score;
        }
    };
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        // Insert all words into the trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Now calculate the sum of prefix scores for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};