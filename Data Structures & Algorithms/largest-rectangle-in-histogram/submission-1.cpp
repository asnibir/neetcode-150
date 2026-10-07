class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0; i<=n; i++) {
            // An imaginary bar of height 0 at the end forces all remaining bars to pop 
            int cur_height = (i == n) ? 0 : heights[i];

            while(!st.empty() and cur_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }

        return maxArea;
    }
};