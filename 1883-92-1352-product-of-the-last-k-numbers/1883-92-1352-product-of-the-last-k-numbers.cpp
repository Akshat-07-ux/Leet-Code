class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts = {1}; // Initialize with 1 for easier calculations
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the prefix product array since any number multiplied by 0 results in 0
            prefixProducts = {1};
        } else {
            // Store the prefix product
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0; // If k exceeds available numbers, return 0 (since a 0 was added in between)
        }
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */