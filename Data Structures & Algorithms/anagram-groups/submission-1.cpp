class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs) {
            int cnt[26] = {0};
            for(char ch: str) {
                cnt[ch - 'a']++;
            }

            string key = "";
            for(int i=0; i<26; i++) {
                key += '#';
                key += to_string(cnt[i]);
            }
            mp[key].push_back(str);

        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for(auto& pair: mp) {
            // ans.push_back(pair.second); // copy
            ans.push_back(move(pair.second)); // move
        }
        return ans;
    }
};
