// O(n log(n))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int num: nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& m: mp) {
            bucket[m.second].push_back(m.first);
        }

        vector<int> ans;
        for(int i=nums.size(); i>0; i--) {
            for(auto num: bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
