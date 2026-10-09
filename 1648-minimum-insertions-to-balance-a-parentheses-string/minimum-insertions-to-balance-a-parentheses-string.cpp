class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int minInsertionsToBalanceString = 0;
        stack<char> st;

        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                st.push(s[i]);
                i++;
            } 
            else if (s[i] == ')') {
                if (st.empty()) {
                    minInsertionsToBalanceString++;
                    if (i + 1 < n && s[i + 1] == ')') {
                        i += 2;
                    } else {
                        minInsertionsToBalanceString++;
                        i += 1;
                    }
                } 
                else {
                    if (i + 1 < n && s[i + 1] == ')') {
                        st.pop();
                        i += 2;
                    } else {
                        st.pop();
                        minInsertionsToBalanceString += 1;
                        i += 1;
                    }
                }
            }
        }
        return minInsertionsToBalanceString + st.size() * 2;
    }
};