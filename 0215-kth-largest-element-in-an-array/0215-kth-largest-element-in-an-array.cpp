class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue pq(nums.begin(), nums.end());
        
        int val;
        for (int i = 0; i < k; ++i) {
            val = pq.top();
            pq.pop();
        }
        return val;
    }
};
