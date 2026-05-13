class Solution {
    bool stack_pop(stack<char>& st, char& ch) {
        char ch_match;
        if(ch == ')') ch_match = '(';
        else if(ch == '}') ch_match = '{';
        else ch_match = '[';
        if(!st.empty() && st.top() == ch_match) {
            st.pop();
            return true;
        }
        else
            return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s) {
            if(ch == '(' ||ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            else if(ch == ')' ||ch == '}' || ch == ']') {
                if(!stack_pop(st,ch))
                    return false;
            }
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};
