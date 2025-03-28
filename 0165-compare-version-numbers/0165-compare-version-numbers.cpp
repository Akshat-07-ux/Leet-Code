class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();
        
        // Traverse through both version strings
        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            
            // Extract the revision number from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Extract the revision number from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compare the current revisions
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            // Move to the next revision
            i++;
            j++;
        }
        
        // If all revisions are equal
        return 0;
    }
};