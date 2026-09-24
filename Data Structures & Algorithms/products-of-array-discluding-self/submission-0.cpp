class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int siz = nums.size();
        vector<int>left(siz, 0);
        vector<int>right(siz, 0);
        left[0] = 1;
        for(int i=1; i<siz; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        right[siz-1] = 1;
        for(int i=siz-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        for(int i=0; i<siz; i++) {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
};