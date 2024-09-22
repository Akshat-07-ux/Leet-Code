class Solution {
public:
    // Function to calculate the number of numbers with prefix `prefix` between 1 and `n`.
    long long countSteps(long long prefix, long long n) {
        long long steps = 0;
        long long first = prefix;
        long long last = prefix;
        
        // We explore numbers with the current prefix and their potential children.
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int current = 1; // Start from the smallest number in lexicographical order, which is 1.
        k--; // We decrement k because we start counting from 1.
        
        while (k > 0) {
            long long steps = countSteps(current, n);
            
            // If the subtree rooted at `current` contains fewer than `k` numbers,
            // we move to the next sibling.
            if (steps <= k) {
                k -= steps; // Skip over this whole subtree.
                current++;  // Move to the next sibling.
            } else {
                // Otherwise, we descend into the current subtree.
                current *= 10; // Move to the next level (deeper).
                k--; // We're visiting `current` itself, so reduce k by 1.
            }
        }
        
        return current;
    }
};