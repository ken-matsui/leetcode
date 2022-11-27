class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string table[] = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };
        set<string> morses{};
        for (const string& w : words) {
            morses.emplace(
                accumulate(
                    w.cbegin(), w.cend(), string{}, 
                    [&](string acc, char c) {
                        return acc + table[static_cast<int>(c - 'a')];
                    }
                )
            );
        }
        return morses.size();
    }
};
