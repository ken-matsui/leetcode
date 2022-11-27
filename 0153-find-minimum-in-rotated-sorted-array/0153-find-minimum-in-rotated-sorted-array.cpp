class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int start = 0, end = nums.size() - 1;
        if (nums[start] < nums[end]) {
            // not rotated
            return nums[0];
        }

        while (start <= end) {
            const int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            } else if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            } else if (nums[0] < nums[mid]) {
                start += 1;
            } else {
                end -= 1;
            }
        }
        return -1;
    }
};
