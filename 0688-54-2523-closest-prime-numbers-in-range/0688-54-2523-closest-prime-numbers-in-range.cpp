class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int N = 1e6 + 1; // Maximum constraint
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        
        // Sieve of Eratosthenes
        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect primes in range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) return {-1, -1}; // No valid pair

        // Find the closest prime pair
        int minDiff = 1e6, num1 = -1, num2 = -1;
        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return {num1, num2};
    }
};