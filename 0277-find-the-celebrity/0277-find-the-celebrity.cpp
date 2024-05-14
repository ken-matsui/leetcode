/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    int n;
    
    bool knowsNoOne(int i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (knows(i, j)) {
                return false;
            }
        }
        return true;
    }
    
    bool knownByEveryone(int i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (!knows(j, i)) {
                return false;
            }
        }
        return true;
    }

public:
    int findCelebrity(int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) {
            if (knowsNoOne(i) && knownByEveryone(i)) {
                return i;
            }
        }
        return -1;
    }
};
