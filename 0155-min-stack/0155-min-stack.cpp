class MinStack {
    int minVal = INT_MAX;
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        minVal = min(minVal, val);
        minSt.push(minVal);
    }

    void pop() {
        st.pop();
        minSt.pop();
        if (!minSt.empty()) {
            minVal = minSt.top();
        } else {
            minVal = INT_MAX;
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
