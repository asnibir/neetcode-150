class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> freq1;
        for(char ch: s1) {
            freq1[ch]++;
        }
        int uniqChars = freq1.size();
        for(int i=0; i<s2.size(); i++) {
            map<char, int> freq2;
            int eqFreqChars = 0;
            for(int j=i; j<s2.size(); j++) {
                char c = s2[j];
                freq2[c]++;

                if(freq1[c] < freq2[c]) {
                    break;
                }

                if(freq1[c] == freq2[c]) {
                    eqFreqChars++;
                }

                if(uniqChars == eqFreqChars) {
                    return true;
                }
            }
        }

        return false;
    }
};
