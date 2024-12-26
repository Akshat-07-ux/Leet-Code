class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word; // Mark the end of a word
    }

    void backtrack(vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& result) {
        char letter = board[row][col];
        int index = letter - 'a';

        // Return if this path is invalid
        if (!node->children[index]) return;

        node = node->children[index];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear(); // Avoid duplicate results
        }

        board[row][col] = '#'; // Mark the cell as visited

        // Explore all possible directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && board[newRow][newCol] != '#') {
                backtrack(board, newRow, newCol, node, result);
            }
        }

        board[row][col] = letter; // Restore the cell
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Step 1: Build a Trie for the words
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }

        // Step 2: Perform backtracking on the board
        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                backtrack(board, i, j, root, result);
            }
        }

        return result;
    }
};