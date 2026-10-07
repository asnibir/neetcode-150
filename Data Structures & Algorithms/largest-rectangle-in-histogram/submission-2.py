class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        maxArea = 0
        st = []

        for i in range(n+1):
            while st and (i == n or heights[st[-1]] >= heights[i]):
                h = heights[st.pop()]
                w = i if not st else i - st[-1] -1
                maxArea = max(maxArea, h*w)
            st.append(i)
        return maxArea
        