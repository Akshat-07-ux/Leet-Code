class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; // A valid tree starts with one available slot (root)

        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') continue; // Skip commas

            // Reduce slots as we're using one for the current node
            slots--;

            // If at any point slots become negative, it's invalid
            if (slots < 0) return false;

            // If it's not a null node ('#'), it adds two more child slots
            if (preorder[i] != '#') {
                // Move index to the end of the current number
                while (i < preorder.size() && preorder[i] != ',') i++;
                slots += 2; // A non-null node provides two new slots
            }
        }

        // At the end, all slots must be used up for a valid serialization
        return slots == 0;
    }
};
