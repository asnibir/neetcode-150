class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        longest = 0
        for num in st:
            if(num - 1) not in st:
                cur = num
                length = 1
                while(cur+1) in st:
                    cur += 1
                    length += 1
                longest = max(longest, length)

        return longest