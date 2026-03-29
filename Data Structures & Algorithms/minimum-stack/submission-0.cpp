class MinStack {
    vector<int> stack;
    deque<int> min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(min.size() > 0) {
        if(val <= min.back()) {
            min.push_back(val);            
        } else {
            min.push_front(val);
        }
        }else {
            min.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if(min.back() == stack.back()) {
            min.pop_back();
        } else if(min.front() == stack.front()) {
            min.pop_front();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};
