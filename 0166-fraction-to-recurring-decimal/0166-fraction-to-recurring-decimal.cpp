class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Handle zero numerator
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long to prevent overflow
        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);

        // Append the integer part
        result += to_string(num / denom);

        // Calculate the remainder
        long long remainder = num % denom;
        if (remainder == 0) return result; // No fractional part

        result += "."; // Add decimal point

        // Map to store the index of each remainder
        unordered_map<long long, int> remainderIndexMap;

        // Process the fractional part
        while (remainder != 0) {
            // If the remainder is already seen, it's a repeating fraction
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                result.insert(remainderIndexMap[remainder], "(");
                result += ")";
                return result;
            }

            // Store the index of the current remainder
            remainderIndexMap[remainder] = result.size();

            // Multiply the remainder by 10 and get the next digit
            remainder *= 10;
            result += to_string(remainder / denom);

            // Update the remainder
            remainder %= denom;
        }

        return result;
    }
};