static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return nullptr;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lMax = 0, rMax = 0, ans = 0;

        while(l < r) {
            if(height[l] <= height[r]) {
                lMax = max(lMax, height[l]);
                ans += lMax - height[l];
                l++;
            }
            else {
                rMax = max(rMax, height[r]);
                ans += rMax - height[r];
                r--;
            }
        }
        return ans;
    }
};
