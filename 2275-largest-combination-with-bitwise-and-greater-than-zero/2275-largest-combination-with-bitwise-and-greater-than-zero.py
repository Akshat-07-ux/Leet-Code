from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        max_combination_size = 0
        
        # Loop over each bit position (0 to 23 for numbers up to 10^7)
        for bit in range(24):
            count = 0
            
            # Count how many numbers have the current bit set
            for num in candidates:
                if num & (1 << bit):
                    count += 1
            
            # Update the maximum combination size with the current count
            max_combination_size = max(max_combination_size, count)
        
        return max_combination_size
