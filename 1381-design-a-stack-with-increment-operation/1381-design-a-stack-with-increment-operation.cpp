class CustomStack {
 int maxSize;               // Maximum size of the stack
    vector<int> stack;         // The actual stack to store elements
    vector<int> inc;           // Array to keep track of increment values
    
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;       // Initialize max size of the stack
        inc.resize(maxSize, 0);        // Initialize the increment array
    }
    
    void push(int x) {
        // Push x if stack hasn't reached the maxSize
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;                 // Return -1 if stack is empty
        }
        
        int idx = stack.size() - 1;     // Index of the top element
        int result = stack.back() + inc[idx]; // Apply the increment value
        stack.pop_back();               // Remove the top element
        
        // Pass down the increment value to the previous element if exists
        if (idx > 0) {
            inc[idx - 1] += inc[idx];
        }
        
        inc[idx] = 0;                   // Reset the increment for this element
        return result;
    }
    
    void increment(int k, int val) {
        // Increment the bottom k elements (or all elements if less than k)
        int limit = min(k, (int)stack.size());  // Increment only up to the stack size
        if (limit > 0) {
            inc[limit - 1] += val;      // Add increment to the bottom-most k-th element
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */