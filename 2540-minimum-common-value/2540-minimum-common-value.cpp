class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int n : nums1) {
            if (binary_search(nums2.begin(), nums2.end(), n)) {
                return n;
            }
        }
        return -1;
    }
};
