class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, read = 0;
        int n = chars.size();

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count how many times currentChar repeats
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // If count > 1, write each digit of the count
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};