class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;
                char topEle = st.top();
                if ((ch == ')' && topEle == '(') ||
                    (ch == '}' && topEle == '{') ||
                    (ch == ']' && topEle == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};