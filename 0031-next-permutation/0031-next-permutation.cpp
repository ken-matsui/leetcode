// ref: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const size_t size = nums.size();

        // 1. Find the largest index k such that a[k] < a[k + 1].
        int k = size - 2;
    	for (; k >= 0; --k) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
            // If no such index exists, the permutation is the last permutation.
    	    reverse(nums.begin(), nums.end());
    	} else {
            // 2. Find the largest index l greater than k such that a[k] < a[l].
    	    for (int l = size - 1; l > k; --l) {
                if (nums[k] < nums[l]) {
                    // 3. Swap the value of a[k] with that of a[l].
                    swap(nums[k], nums[l]);
                    break;
                }
            } 

            // 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
