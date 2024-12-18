class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Count the frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Max heap to maintain characters in descending order
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({char('a' + i), freq[i]});
            }
        }

        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();

            // Add the character up to the repeatLimit or its remaining count
            int use = min(count, repeatLimit);
            result.append(use, ch);
            count -= use;

            // Check if we need to add another character to break the sequence
            if (count > 0) {
                if (pq.empty()) {
                    // If no other characters are available, stop
                    break;
                }

                // Add one character of the next most frequent character
                auto [nextCh, nextCount] = pq.top();
                pq.pop();

                result.push_back(nextCh);
                nextCount--;

                // Push the characters back into the priority queue if they are still available
                if (nextCount > 0) {
                    pq.push({nextCh, nextCount});
                }
                pq.push({ch, count});
            }
        }

        return result;
    }
};