class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount;
        stack<map<string, int>> stk;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = i > start ? stoi(formula.substr(start, i - start)) : 1;
                
                map<string, int> top = stk.top();
                stk.pop();
                
                for (auto &[atom, count] : top) {
                    top[atom] = count * multiplier;
                }
                
                if (!stk.empty()) {
                    for (auto &[atom, count] : top) {
                        stk.top()[atom] += count;
                    }
                } else {
                    for (auto &[atom, count] : top) {
                        atomCount[atom] += count;
                    }
                }
            } else {
                int start = i;
                i++; // Move past the first uppercase letter
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = i > start ? stoi(formula.substr(start, i - start)) : 1;
                
                if (!stk.empty()) {
                    stk.top()[atom] += count;
                } else {
                    atomCount[atom] += count;
                }
            }
        }

        if (!stk.empty()) {
            for (auto &[atom, count] : stk.top()) {
                atomCount[atom] += count;
            }
        }

        ostringstream os;
        for (auto &[atom, count] : atomCount) {
            os << atom;
            if (count > 1) os << count;
        }

        return os.str();
    }
};