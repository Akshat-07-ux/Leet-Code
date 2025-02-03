/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasNextElement;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Preload the first element if available
        hasNextElement = Iterator::hasNext();
        if (hasNextElement) {
            nextElement = Iterator::next();
        }
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextElement;
    }
    
    int next() {
        int current = nextElement;
        hasNextElement = Iterator::hasNext();
        if (hasNextElement) {
            nextElement = Iterator::next();
        }
        return current;
    }
    
    bool hasNext() const {
        return hasNextElement;
    }
};