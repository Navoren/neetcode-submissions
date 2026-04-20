class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mppS;
        unordered_map<char,int> mppT;
        if(s.length() != t.length()) return false;
        for(int i =0; i<s.length(); i++){
            mppS[s[i]]++;
            mppT[t[i]]++;
        }
        return mppS == mppT;
    }
};
