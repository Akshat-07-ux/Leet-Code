class Solution{
    private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        // Seed the random number generator with current time
        std::srand(std::time(nullptr));
    }
    
    int getRandom() {
        int result = head->val;
        ListNode* current = head->next;
        int index = 2; // since we already considered the first node

        while (current != nullptr) {
            // Generate a random number in [0, index-1]
            int randIndex = rand() % index;
            if (randIndex == 0) {
                result = current->val;
            }
            current = current->next;
            index++;
        }
        return result;
    }
};
