class Solution {
public:
    int evalRPN(vector<string>& tkn) {
        stack<int> st;
        for(int i=0; i<tkn.size(); i++){
            if(tkn[i] == "+"){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(n1 + n2);
            }else if(tkn[i] == "*"){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(n1 * n2);
            }else if(tkn[i] == "-"){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(n1 - n2);
            }else if(tkn[i] == "/"){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(n1 / n2);
            }else{
                st.push(stoi(tkn[i]));
            }
        }
        return st.top();
    }
};