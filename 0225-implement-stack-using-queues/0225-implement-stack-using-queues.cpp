class MyStack {
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        queue<int> q2;
        int v;
        while (!q.empty()) {
            v = q.front();
            q.pop();
            if (!q.empty()) {
                q2.push(v);
            }
        }
        q = q2;
        return v;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
