class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s) {
            if(ch == '(' ||ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            else if(ch == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if(ch == '}') {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if(ch == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
