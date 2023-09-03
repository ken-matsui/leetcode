class MyCircularQueue {
    int capacity;
    int size = 0;
    list<int> queue;
    
public:
    MyCircularQueue(int k) {
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue.push_back(value);
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        queue.pop_front();
        --size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return *queue.begin();
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return *queue.rbegin();
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */