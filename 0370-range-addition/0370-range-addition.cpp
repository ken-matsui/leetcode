class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        for (const auto& u : updates) {
            const int start = u[0];
            const int end = u[1];
            const int val = u[2];

            arr[start] += val;
            
            if (end < length - 1) {
                arr[end + 1] -= val;
            }
        }

        for(int i = 1; i < length; i++) {
            arr[i] += arr[i - 1];
        }
        return arr;
    }
};
