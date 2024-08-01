class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            // Determine the range of words that fit on the current line.
            int totalChars = words[index].length();
            int last = index + 1;
            while (last < n) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            // Build the current line.
            std::stringstream line;
            int numOfWords = last - index;
            int numOfSpaces = maxWidth - totalChars;

            // If it's the last line or there is only one word, left justify.
            if (last == n || numOfWords == 1) {
                for (int i = index; i < last; ++i) {
                    line << words[i];
                    if (i < last - 1) line << " ";
                }
                while (line.str().length() < maxWidth) {
                    line << " ";
                }
            } else {
                // Fully justify.
                int spaces = numOfSpaces / (numOfWords - 1);
                int extraSpaces = numOfSpaces % (numOfWords - 1);
                for (int i = index; i < last; ++i) {
                    line << words[i];
                    if (i < last - 1) {
                        for (int j = 0; j <= (spaces + (i - index < extraSpaces ? 1 : 0)); ++j) {
                            line << " ";
                        }
                    }
                }
            }

            result.push_back(line.str());
            index = last;
        }

        return result;
    }
};