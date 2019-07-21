class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> t;
        while(!data.empty()) {
            t.push(data.top());
            data.pop();
        }
        int x = t.top();
        t.pop();
        while(!t.empty()) {
            data.push(t.top());
            t.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> t;
        while(!data.empty()) {
            t.push(data.top());
            data.pop();
        }
        int x = t.top();
        while(!t.empty()) {
            data.push(t.top());
            t.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.size() == 0;
    }
private:
    stack<int> data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */