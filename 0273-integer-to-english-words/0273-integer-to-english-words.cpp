class Solution {
private:
    const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num >= 1000000000) return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
        if (num >= 1000000) return helper(num / 1000000) + " Million" + helper(num % 1000000);
        if (num >= 1000) return helper(num / 1000) + " Thousand" + helper(num % 1000);
        if (num >= 100) return helper(num / 100) + " Hundred" + helper(num % 100);
        if (num >= 20) return " " + tens[num / 10] + helper(num % 10);
        if (num >= 1) return " " + ones[num];
        return "";
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = helper(num);
        return result.substr(1); // Remove leading space
    }
};