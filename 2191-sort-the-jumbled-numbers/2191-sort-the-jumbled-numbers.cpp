class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long, int>> mapped;

        for (int i = 0; i < n; i++) {
            long long mappedValue = getMappedValue(nums[i], mapping);
            mapped.push_back({mappedValue, i});
        }

        stable_sort(mapped.begin(), mapped.end());

        vector<int> result;
        for (auto& p : mapped) {
            result.push_back(nums[p.second]);
        }

        return result;
    }

private:
    long long getMappedValue(int num, vector<int>& mapping) {
        if (num == 0) return mapping[0];

        long long mappedValue = 0;
        long long multiplier = 1;

        while (num > 0) {
            int digit = num % 10;
            mappedValue += (long long)mapping[digit] * multiplier;
            multiplier *= 10;
            num /= 10;
        }

        return mappedValue;
    }
};