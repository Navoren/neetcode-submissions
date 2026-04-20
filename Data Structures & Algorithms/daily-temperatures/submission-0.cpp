class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> res(temps.size(), 0);
        stack<pair<int,int>> st;

        for(int i=0; i<temps.size(); i++){
            int t = temps[i];
            while(!st.empty() && t > st.top().first){
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }
            st.push({t, i});
        }
        return res;
    }
};
