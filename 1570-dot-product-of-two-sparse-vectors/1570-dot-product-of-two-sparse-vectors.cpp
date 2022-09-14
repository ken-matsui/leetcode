class SparseVector {
public:
    vector<int> v;
    
    SparseVector(vector<int> &nums) : v(nums) {} 

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        const size_t size = v.size();
        for (int i = 0; i < size; ++i) {
            sum += v[i] * vec.v[i];
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
