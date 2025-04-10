/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();

        // If it's just an integer (no brackets), return as simple NestedInteger
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> stk;
        int num = 0;
        bool negative = false;
        bool hasNum = false;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (ch == '-') {
                negative = true;
            } else if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                hasNum = true;
            } else if (ch == '[') {
                stk.push(NestedInteger());
            } else if (ch == ',' || ch == ']') {
                if (hasNum) {
                    if (negative) num = -num;
                    stk.top().add(NestedInteger(num));
                }
                num = 0;
                hasNum = false;
                negative = false;

                if (ch == ']' && stk.size() > 1) {
                    NestedInteger ni = stk.top(); stk.pop();
                    stk.top().add(ni);
                }
            }
        }

        return stk.top();
    }
};