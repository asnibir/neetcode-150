class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for ch in s:
            if ch == '(' or ch == '{' or ch == '[':
                st.append(ch)
            else:
                if not st:
                    return False
                top = st[-1]
                if (ch == ')' and top == '(') or (ch == '}' and top == '{') or (ch == ']' and top == '['):
                    st.pop()
                else:
                    return False
        
        return len(st) == 0

        