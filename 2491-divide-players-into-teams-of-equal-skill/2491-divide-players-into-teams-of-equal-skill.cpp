class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int teamSkill = skill[0] + skill[n - 1];
        long long totalChemistry = 0;

        for (int i = 0; i < n / 2; ++i) {
            int currentPairSkill = skill[i] + skill[n - i - 1];
            if (currentPairSkill != teamSkill) {
                return -1;
            }
            totalChemistry += static_cast<long long>(skill[i]) * skill[n - i - 1];
        }

        return totalChemistry;
    }
};