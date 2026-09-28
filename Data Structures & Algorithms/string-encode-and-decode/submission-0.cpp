class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string res;
        for(const string& s: strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> ans;
        int i=0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + length;
            ans.push_back(s.substr(i, length));
            i = j;
        }
        return ans;
    }
};
