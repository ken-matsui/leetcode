class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return {0, 0};
            } else {
                return {-1, -1};
            }
        }
        
        int lo = 0;
        int hi = nums.size() - 1;
        int mi = -1;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            
            if (nums[mi] == target) {
                break;
            } else if (nums[mi] < target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        
        // not found
        if (mi == -1 || lo > hi) {
            return {-1, -1};
        }

        // find range
        int start = mi;
        int end = mi;
        while (start > 0 && nums[start-1] == target) {
            --start;
        }
        while (end < nums.size() - 1 && nums[end+1] == target) {
            ++end;
        }
        return {start, end};
    }
};
