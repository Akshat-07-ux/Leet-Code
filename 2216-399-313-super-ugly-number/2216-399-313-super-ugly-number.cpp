class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNumbers(n, 1); // Store super ugly numbers
        int k = primes.size();
        vector<int> index(k, 0); // Track indices for each prime
        vector<long> nextMultiple(primes.begin(), primes.end()); // Next multiples of primes

        for (int i = 1; i < n; i++) {
            // Find the minimum among nextMultiples
            long nextUgly = *min_element(nextMultiple.begin(), nextMultiple.end());
            uglyNumbers[i] = nextUgly;

            // Update indices and nextMultiples for each prime
            for (int j = 0; j < k; j++) {
                if (nextMultiple[j] == nextUgly) {
                    index[j]++;
                    nextMultiple[j] = (long) uglyNumbers[index[j]] * primes[j];
                }
            }
        }
        return uglyNumbers[n - 1];
    }
};