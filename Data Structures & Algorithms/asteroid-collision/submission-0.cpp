class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asts) {
        stack<int> st;
        
        for(int a : asts) {
            bool alive = true;
            
            while(alive && a < 0 && !st.empty() && st.top() > 0) {
                if(st.top() < -a) { 
                    st.pop();
                } else if(st.top() == -a) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            
            if(alive) st.push(a);
        }
        
        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        
        return res;
    }
};
