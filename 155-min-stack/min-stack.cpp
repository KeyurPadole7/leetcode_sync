class MinStack {
public:
    stack<int> s;
    stack<int> gm;
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            gm.push(val);
        }
        else{
            if(val<=gm.top()) gm.push(val);
            s.push(val);
        }
    }
    
    void pop() {
        if(s.top() == gm.top()) gm.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return gm.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */