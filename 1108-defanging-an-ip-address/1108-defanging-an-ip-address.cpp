class Solution {
public:
    string defangIPaddr(string address) {
        const auto first = address.begin();
        string::size_type itr = 0;
        for (int i = 0; i < 3; ++i) {
            itr = address.find(".", itr);
            address.replace(itr, 1, "[.]");
            itr += 2;
        }
        return address;
    }
};