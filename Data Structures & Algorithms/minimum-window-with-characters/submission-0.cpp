class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int reqSize = t.size();
        int l = 0;
        int r = 0;
        int n = s.size();
        int start = 0;
        int minLen = INT_MAX;
        while(r < n){
            if(need[s[r]] > 0){
                reqSize--;
            }
            need[s[r]]--;
            r++;

            while(reqSize == 0){
                if(r-l < minLen){
                    minLen = r-l;
                    start = l;
                }
                need[s[l]]++;
                if (need[s[l]] > 0) {
                    reqSize++;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
