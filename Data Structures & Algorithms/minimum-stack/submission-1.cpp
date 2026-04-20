class MinStack {
    
private:
    long long mini;
    stack<long long> st;

public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }else{
            if(val < mini){
                long long newVal = 2LL * val - mini;
                st.push(newVal);
                mini = val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2LL * mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top() >= mini) return st.top();
        else{
            return mini;
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};