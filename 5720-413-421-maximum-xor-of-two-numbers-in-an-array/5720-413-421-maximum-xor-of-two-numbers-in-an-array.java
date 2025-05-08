class Solution {
   public int findMaximumXOR(int[] nums) {
        int maxResult = 0;
        int mask = 0;
        
        // We need to find the maximum XOR, so we start checking from the most significant bit
        // The maximum integer in the constraint is 2^31 - 1, so we start from bit 30
        for (int i = 30; i >= 0; i--) {
            // Generate a mask with all bits from 30th position to current i position set to 1
            mask = mask | (1 << i);
            
            // Use a HashSet to store all possible prefixes for the current bit
            Set<Integer> prefixes = new HashSet<>();
            
            // Add the prefixes of all numbers in the array to the HashSet
            for (int num : nums) {
                // We only care about the bits from the leftmost bit to the current bit
                prefixes.add(num & mask);
            }
            
            // Try to find two prefixes whose XOR equals to the potential maxResult with current bit set
            int potentialMax = maxResult | (1 << i);
            
            for (int prefix : prefixes) {
                // If prefix ^ target = potentialMax, then target = prefix ^ potentialMax
                // If target exists in our prefixes, we found a match
                int target = prefix ^ potentialMax;
                if (prefixes.contains(target)) {
                    maxResult = potentialMax;
                    break;
                }
            }
        }
        
        return maxResult;
    }
}