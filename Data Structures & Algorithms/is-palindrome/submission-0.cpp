class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](char c){
            return tolower(c); 
        });

        int i = 0, j = s.size() - 1;

        while(i < j) {
            if(!isAlphaNeumeric(s[i])) {
                i++;
            }
            else if(!isAlphaNeumeric(s[j])) {
                j--;
            }
            else {
                if(s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }

    bool isAlphaNeumeric(char c) {
        if ((c >= 'a' and c<= 'z') or (c >= '0' and c <= '9')) {
            return true;
        }
        return false;
    }
};
