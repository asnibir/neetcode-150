class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, ans = 0;
        for(int r=0; r<s.size(); r++) {
            freq[s[r] - 'A']++;
            int maxFreq = 0;
            for(int i=0; i<26; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }

            while((r-l+1) - maxFreq> k) {
                freq[s[l] - 'A']--;
                l++;

                maxFreq = 0;
                for(int i=0; i<26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
