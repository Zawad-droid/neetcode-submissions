class MinStack {
    vector<int> v;
    vector<int> minv;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        if(minv.empty() || val <= minv.back()) minv.push_back(val);
    }
    
    void pop() {
        if(v.back() == minv.back()){
            minv.pop_back();
        }
        v.pop_back();
    }
    
    int top() {
        return  v[v.size() - 1];
    }
    
    int getMin() {
        return minv.back();
    }
};
