class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n - 1);
        string result = "";
        int count = 1;
        char current = prev[0];
        
        for (int i = 1; i < prev.length(); i++) {
            if (prev[i] == current) {
                count++;
            } else {
                result += to_string(count) + current;
                current = prev[i];
                count = 1;
            }
        }
        
        result += to_string(count) + current;
        return result;
    }
};