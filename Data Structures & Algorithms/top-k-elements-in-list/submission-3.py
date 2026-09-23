# O(n + m). Since m ≤ n, overall O(n).
# Bucket Sort

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        for num in nums:
            mp[num] = mp.get(num, 0) + 1
        
        bucket = [[] for i in range(len(nums) + 1)]
        for val, freq in mp.items():
            bucket[freq].append(val)
        
        ans = []
        for i in range(len(nums), 0, -1):
            for num in bucket[i]:
                ans.append(num)
                if len(ans) == k:
                    return ans

        return ans
        