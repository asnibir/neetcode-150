# DP
# Prefix and Suffix Array
class Solution:
    def trap(self, height: List[int]) -> int:
        siz = len(height)
        if siz == 0:
            return 0
        
        lMax = [0]*siz
        rMax = [0]*siz

        lMax[0] = height[0]
        for i in range(1, siz):
            lMax[i] = max(lMax[i-1], height[i])
        
        rMax[siz-1] = height[siz-1]
        for i in range(siz-2, -1, -1):
            rMax[i] = max(rMax[i+1], height[i])
        
        ans = 0
        for i in range(siz):
            ans += min(lMax[i], rMax[i]) - height[i]

        return ans

        

        
        


        