class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int maxLen = 0, l = 0;

        for (int r = 0; r < s.size(); r++) {
            if (last[s[r]] >= l) {
                l = last[s[r]] + 1;
            }
            last[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};