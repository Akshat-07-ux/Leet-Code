class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to recursively find the k-th bit in S_n
        return findKthBitRecursive(n, k);
    }
    
private:
    char findKthBitRecursive(int n, int k) {
        // Base case: If n is 1, the string S1 is "0"
        if (n == 1) return '0';
        
        // Length of the Sn string is 2^n - 1
        int length = (1 << n) - 1;  // Equivalent to 2^n - 1
        int middle = (length / 2) + 1;  // Middle element index
        
        if (k == middle) {
            // If k is the middle element, it's always '1'
            return '1';
        } else if (k < middle) {
            // If k is in the first half, it matches S_{n-1}
            return findKthBitRecursive(n - 1, k);
        } else {
            // If k is in the second half, we find its mirrored counterpart in the first half,
            // which is at position length - k + 1, then invert it.
            char mirroredBit = findKthBitRecursive(n - 1, length - k + 1);
            return mirroredBit == '0' ? '1' : '0';
        }
    }
};