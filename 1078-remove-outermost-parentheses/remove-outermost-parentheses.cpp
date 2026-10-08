class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 1;
        int n = s.size();
        for ( int i = 1 ; i < n ; i ++ ) {
            if ( s[i] == '(' ) {
                cnt++;
                if ( cnt == 1 ) continue;
                else ans += s[i];
            }
            else {
                cnt--;
                if ( cnt == 0 ) continue;
                else ans += s[i];
            }
        }
        return ans;
    }
};