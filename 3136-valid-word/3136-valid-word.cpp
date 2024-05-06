class Solution {
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }
        }

        bool hasVowel = false;
        bool hasConso = false;
        for (char c : word) {
            if (isalpha(c)) {
                if (vowels.contains(tolower(c))) {
                    hasVowel = true;
                } else {
                    hasConso = true;
                }

                if (hasVowel && hasConso) {
                    return true;
                }
            }
        }
        return false;
    }
};
