class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;

        int s1Count = 0, s2Count = 0, index = 0;
        int len1 = s1.size(), len2 = s2.size();

        // record the count of s1 and corresponding s2 index at that point
        vector<int> s1CountAtIndex(len2, 0), s2CountAtIndex(len2, 0);

        while (s1Count < n1) {
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == len2) {
                        index = 0;
                        s2Count++;
                    }
                }
            }
            s1Count++;

            // Check if we have seen this index before
            if (s1CountAtIndex[index] != 0) {
                // Found a cycle
                int preCycleS1Count = s1CountAtIndex[index];
                int preCycleS2Count = s2CountAtIndex[index];

                int cycleS1Count = s1Count - preCycleS1Count;
                int cycleS2Count = s2Count - preCycleS2Count;

                int remainingS1 = n1 - s1Count;

                int cycles = remainingS1 / cycleS1Count;

                s1Count += cycles * cycleS1Count;
                s2Count += cycles * cycleS2Count;
            }

            // Record current state
            s1CountAtIndex[index] = s1Count;
            s2CountAtIndex[index] = s2Count;
        }

        return s2Count / n2;
    }
};