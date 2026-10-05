class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int score = 0;
        int count = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( s[i] == '(') {
                count++;
            }
            else if ( s[i] == ')' ) {
                count--;
                if ( s[i-1] == '(' ) score += 1 << count;
            }
        }
        return score;
    }
};