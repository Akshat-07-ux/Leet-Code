class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        
        for (const string& operation : logs) {
            if (operation == "../") {
                depth = max(0, depth - 1);
            } else if (operation != "./") {
                depth++;
            }
        }
        
        return depth;
    }
};