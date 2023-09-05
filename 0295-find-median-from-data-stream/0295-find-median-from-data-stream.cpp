class MedianFinder {
    template <typename T> using MaxHeap = priority_queue<T>;
    template <typename T>
    using MinHeap = priority_queue<T, vector<T>, greater<T>>;

    MaxHeap<int> left;
    MinHeap<int> right;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Insert
        if (left.empty()) {
            left.push(num);
        } else if (num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Self-balancing
        if (left.size() > right.size() + 1) {
            const int maxVal = left.top();
            right.push(maxVal);
            left.pop();
        } else if (right.size() > left.size()) {
            const int minVal = right.top();
            left.push(minVal);
            right.pop();
        }
    }

    double findMedian() {
        if ((left.size() + right.size()) % 2 == 0) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
