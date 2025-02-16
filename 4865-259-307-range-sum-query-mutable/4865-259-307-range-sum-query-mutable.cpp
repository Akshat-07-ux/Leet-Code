class NumArray {
private:
    vector<int> segTree; // Segment Tree
    int n; // Size of the input array

    // Build the segment tree
    void buildTree(vector<int>& nums, int start, int end, int node) {
        if (start == end) {
            segTree[node] = nums[start];  // Leaf node
            return;
        }
        int mid = (start + end) / 2;
        buildTree(nums, start, mid, 2 * node + 1);  // Left child
        buildTree(nums, mid + 1, end, 2 * node + 2);  // Right child
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2]; // Sum of left and right child
    }

    // Update the segment tree
    void updateTree(int start, int end, int node, int index, int val) {
        if (start == end) {
            segTree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            updateTree(start, mid, 2 * node + 1, index, val); // Left child
        else
            updateTree(mid + 1, end, 2 * node + 2, index, val); // Right child

        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2]; // Update parent sum
    }

    // Query sum in range [L, R]
    int querySum(int start, int end, int node, int L, int R) {
        if (L > end || R < start) return 0; // Out of range
        if (L <= start && end <= R) return segTree[node]; // Fully within range

        int mid = (start + end) / 2;
        return querySum(start, mid, 2 * node + 1, L, R) + querySum(mid + 1, end, 2 * node + 2, L, R);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0);
        buildTree(nums, 0, n - 1, 0);
    }

    void update(int index, int val) {
        updateTree(0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right) {
        return querySum(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */