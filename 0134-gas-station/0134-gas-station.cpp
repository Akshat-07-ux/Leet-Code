class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;
        
        // Step 1: Calculate total gas and total cost
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        // If total gas is less than total cost, the trip is impossible
        if (totalGas < totalCost) {
            return -1;
        }
        
        // Step 2: Use a greedy approach to find the starting index
        for (int i = 0; i < gas.size(); ++i) {
            currentGas += gas[i] - cost[i];
            
            // If at any point currentGas is negative, reset the starting point
            if (currentGas < 0) {
                startIndex = i + 1; // Reset start to the next station
                currentGas = 0;     // Reset current gas
            }
        }
        
        // Step 3: Return the starting index, which is guaranteed to be valid
        return startIndex;
    }
};