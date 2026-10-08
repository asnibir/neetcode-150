# Jump-Ahead Optimization ($O(n)$ with Hash Map)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        ans, l = 0, 0
        for r, char in enumerate(s):
            if char in last_seen and last_seen[char] >= l:
                l = last_seen[char] + 1
            last_seen[char] = r
            ans = max(ans, r-l+1)
        return ans

        