
class NumberContainers {
public:
    std::unordered_map<int, int> indexToNumber; // Maps index to number
    std::unordered_map<int, std::map<int, bool>> numberToIndices; // Maps number to a sorted map of indices

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // If the index already has a number, remove it from the old mapping
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        
        // Update indexToNumber mapping
        indexToNumber[index] = number;
        
        // Insert into the new mapping
        numberToIndices[number][index] = true;
    }
    
    int find(int number) {
        // If the number exists in the system, return the smallest index
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return numberToIndices[number].begin()->first;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */