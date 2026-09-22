class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int>mp;
        for(auto num: nums) {
            if(!mp[num]) {
                mp[num]++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
