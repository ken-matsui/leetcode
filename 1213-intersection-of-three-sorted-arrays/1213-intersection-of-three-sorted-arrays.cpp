class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                   vector<int>& arr3) {
        vector<int> res;
        for (int i = 0; i < arr1.size(); ++i) {
            if (binary_search(arr2.begin(), arr2.end(), arr1[i]) &&
                binary_search(arr3.begin(), arr3.end(), arr1[i])) {
                res.push_back(arr1[i]);
            }
        }
        return res;
    }
};
