class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        const size_t size = encoded.size();
        vector<int> arr{ first };

        for (int i = 0; i < size; ++i) {
            arr.push_back(arr[i] ^ encoded[i]);
        }

        return arr;
    }
};