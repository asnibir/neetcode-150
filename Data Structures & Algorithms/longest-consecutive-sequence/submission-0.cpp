class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for(int num: st) {
            if(st.find(num - 1) == st.end()) {
                int len = 1;
                int cur = num;
                while(st.find(cur+1) != st.end()) {
                    len++;
                    cur++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
