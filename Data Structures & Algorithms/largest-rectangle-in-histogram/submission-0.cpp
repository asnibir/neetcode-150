class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftBar(n, -1);
        vector<int>rightBar(n, n);
        stack<int> st1;
        stack<int> st2;

        for(int i=0, j=n-1; i<n; i++, j--) {
            while(!st1.empty() and heights[st1.top()] >= heights[i]) {
                st1.pop();
            }
            if(!st1.empty()) {
                leftBar[i] = st1.top();
            }
            st1.push(i);

            while(!st2.empty() and heights[st2.top()] >= heights[j]) {
                st2.pop();
            }
            if(!st2.empty()) {
                rightBar[j] = st2.top();
            }
            st2.push(j);
        }

        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int area = heights[i] * (rightBar[i] - leftBar[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};