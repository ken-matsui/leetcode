class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        if (m > n) {
            // ensure nums1 is smaller
            return findMedianSortedArrays(nums2, nums1);
        }

        int leftLo = 0;
        int leftHi = m;
        int half = (m + n + 1) / 2;

        while (leftLo <= leftHi) {
            int left = leftLo + (leftHi - leftLo) / 2;
            int right = half - left;

            if (left < m && nums1[left] < nums2[right-1]) {
                leftLo = left + 1;
            } else if (left > 0 && nums1[left-1] > nums2[right]) {
                leftHi = left - 1;
            } else {
                int leftMax;
                if (left == 0) {
                    leftMax = nums2[right-1];
                } else if (right == 0) {
                    leftMax = nums1[left-1];
                } else {
                    leftMax = max(nums1[left-1], nums2[right-1]);
                }

                if ((m + n) % 2 == 1) {
                    return leftMax;
                }

                int rightMax;
                if (left == m) {
                    rightMax = nums2[right];
                } else if (right == n) {
                    rightMax = nums1[left];
                } else {
                    rightMax = min(nums1[left], nums2[right]);
                }
                return (leftMax + rightMax) / 2.0;
            }
        }
        return -1;
    }
};
