class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int ans = 0, l = 0;
        for(int r=0; r<s.size(); r++) {
            while(chars.find(s[r]) != chars.end()) {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
