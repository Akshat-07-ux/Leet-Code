class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, size, capacity;

public:
    // Constructor to initialize deque with max size k
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }
    
    // Insert an item at the front of Deque. Return true if successful.
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity; // circular move
        deque[front] = value;
        size++;
        if (size == 1) rear = front; // Update rear when deque was previously empty
        return true;
    }
    
    // Insert an item at the rear of Deque. Return true if successful.
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity; // circular move
        deque[rear] = value;
        size++;
        if (size == 1) front = rear; // Update front when deque was previously empty
        return true;
    }
    
    // Delete an item from the front of Deque. Return true if successful.
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity; // circular move
        size--;
        return true;
    }
    
    // Delete an item from the rear of Deque. Return true if successful.
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity; // circular move
        size--;
        return true;
    }
    
    // Get the front item of the deque. Return -1 if deque is empty.
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    // Get the last item of the deque. Return -1 if deque is empty.
    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
    }
    
    // Check if deque is empty.
    bool isEmpty() {
        return size == 0;
    }
    
    // Check if deque is full.
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */