class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int numerator = 0, denominator = 1, n = 0, d = 0, sign = 1;
        int i = 0, len = expression.size();
        
        while (i < len) {
            
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '+') ? 1 : -1;
                i++;
            }
            
            
            n = 0;
            while (i < len && isdigit(expression[i])) {
                n = n * 10 + (expression[i] - '0');
                i++;
            }
            n *= sign;
            
            
            i++;
            
            
            d = 0;
            while (i < len && isdigit(expression[i])) {
                d = d * 10 + (expression[i] - '0');
                i++;
            }
            
           
            numerator = numerator * d + n * denominator;
            denominator *= d;
            
            
            int gcd = std::gcd(abs(numerator), abs(denominator));
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};