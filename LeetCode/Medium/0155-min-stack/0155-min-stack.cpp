class MinStack {
private:
    stack<vector<int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
            return;
        }
        int minVal = min(val, s.top()[1]);
        s.push({val, minVal});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top()[0];
    }
    
    int getMin() {
        return s.top()[1];
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