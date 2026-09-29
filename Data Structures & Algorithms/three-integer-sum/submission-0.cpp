class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++) {
            int num1 = nums[i];
            int target = 0 - num1;
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k) {
                int num2 = nums[j];
                int num3 = nums[k];
                int sum = num2 + num3;
                if(sum == target) {
                    st.insert({num1, num2, num3});
                    j++;
                    k--;
                }
                else {
                    if(sum > target) {
                        k--;
                    }
                    else {
                        j++;
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
