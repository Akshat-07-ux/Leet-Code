class Solution {
public:
    // Function to solve the sliding puzzle
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2x3 board into a single string for easier manipulation
        string start;
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        // The target solved state
        string target = "123450";

        // Directions for moving the empty square (0): up, down, left, right
        vector<vector<int>> directions = {
            {1, 3},    // moves for position 0
            {0, 2, 4}, // moves for position 1
            {1, 5},    // moves for position 2
            {0, 4},    // moves for position 3
            {1, 3, 5}, // moves for position 4
            {2, 4}     // moves for position 5
        };

        // BFS setup
        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                // Check if we reached the target
                if (current == target) {
                    return moves;
                }

                // Find the index of the empty square (0)
                int zeroIndex = current.find('0');

                // Explore all possible moves for the empty square
                for (int dir : directions[zeroIndex]) {
                    string next = current;
                    swap(next[zeroIndex], next[dir]);

                    // If this state hasn't been visited, add it to the queue
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            moves++;
        }

        // If we exit the loop without finding the target, it's unsolvable
        return -1;
    }
};