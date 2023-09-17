class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }
        if (tasks.size() == 1) {
            return 1;
        }
        
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        
        priority_queue<int> maxHeap;
        for (auto itr : freq) {
            maxHeap.push(itr.second);
        }
        
        int cycles = 0;
    
        while (!maxHeap.empty()) {
            vector<int> tmp;
            
            for (int i = 0; i < n + 1; ++i) {
                if (!maxHeap.empty()) {
                    tmp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            for (int count : tmp) {
                if (--count) {
                    maxHeap.push(count);
                }
            }

            cycles += !maxHeap.empty() ? n + 1 : tmp.size();
        }

        return cycles;
    }
};
