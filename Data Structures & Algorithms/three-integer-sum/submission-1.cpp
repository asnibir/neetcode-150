class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int siz = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < siz-2; i++) {

            // skip duplicate first element
            if(i > 0 and nums[i] == nums[i-1])
                continue;

            // the first number is greater than 0, so no way that sum would be 0.
            if(nums[i] > 0) 
                break;

            int j = i + 1;
            int k = siz - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // skip duplicate second number
                    while(j < k and nums[j] == nums[j+1]) {
                        j++;                        
                    }

                    // skip duplicate third number
                    while(j < k and nums[k] == nums[k-1]) {
                        k--;                        
                    }

                    j++;
                    k--;
                }
                else {
                    if(sum > 0) {
                        k--;
                    }
                    else {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
