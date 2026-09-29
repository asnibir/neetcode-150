class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        siz = len(nums)
        ans = []

        for i in range(siz-2):
            # skip duplicate first element
            if i > 0 and nums[i-1] == nums[i]:
                continue
            
            if nums[i] > 0:
                break
            
            j = i + 1
            k = siz - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j+1]:
                        j += 1
                    while j < k and nums[k] ==  nums[k-1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif total > 0:
                    k -= 1
                else:
                    j += 1
        return ans

            

        