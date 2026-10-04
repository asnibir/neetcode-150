class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& s: tokens) {
            if(s.size() == 1) {
                if(s >= "0" and s <= "9") {
                    st.push(stoi(s));
                }
                else {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    if(s == "+") {
                        st.push(num1 + num2);
                    }
                    else if(s == "-") {
                        st.push(num2 - num1);
                    }
                    else if(s == "*") {
                        st.push(num1 * num2);
                    }
                    else {
                        st.push(num2 / num1);
                    }
                }
            }
            else {
                st.push(stoi(s));
            }
            
        }
        return st.top();
    }
};
