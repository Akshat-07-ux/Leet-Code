class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        // Sort folders in lexicographical order
        std::sort(folder.begin(), folder.end());
        
        std::vector<std::string> result;
        std::string parent = ""; // Track the last added folder that isn't a subfolder
        
        for (const std::string& f : folder) {
            // Check if 'f' is not a subfolder of 'parent'
            if (parent.empty() || f.find(parent + "/") != 0) {
                result.push_back(f);
                parent = f; // Update the new parent folder
            }
        }
        
        return result;
    }

};