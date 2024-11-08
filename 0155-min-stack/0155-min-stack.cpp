class MinStack {
public:
    stack<int> s;      // Primary stack
    stack<int> minS;   // Auxiliary stack to track the minimum element

    MinStack() {
    }

    // Push an element onto the stack
    void push(int val) {
        s.push(val);
        // If the min stack is empty or the current value is less than or equal to the top of min stack
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }

    // Pop the top element from the stack
    void pop() {
        // If the top element is the minimum, pop it from the min stack as well
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }

    // Get the top element of the stack
    int top() {
        return s.top();
    }

    // Retrieve the minimum element from the stack
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */