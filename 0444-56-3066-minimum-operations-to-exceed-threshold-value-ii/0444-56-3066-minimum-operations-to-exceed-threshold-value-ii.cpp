class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Create a min heap priority queue to store the numbers
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Add all numbers to the priority queue
        for (int num : nums) {
            pq.push(num);
        }
        
        int operations = 0;
        
        // Continue operations until all numbers are >= k
        while (pq.size() >= 2 && pq.top() < k) {
            // Get the two smallest numbers
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            
            // Calculate the new number according to the formula
            long long newNum = min(x, y) * 2 + max(x, y);
            
            // Add the new number back to the priority queue
            pq.push(newNum);
            
            operations++;
        }
        
        // If the smallest remaining number is still less than k,
        // it means we couldn't reach the target
        if (pq.top() < k) {
            return -1;  // This case won't occur given the problem constraints
        }
        
        return operations;
    }
};