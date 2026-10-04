class Solution {
public:
    bool f ( int i , int count , string& s , vector<vector<int>>&dp ) {
        int n = s.size();
        if ( count < 0 ) return false;
        if ( i == n ) return count == 0 ;
        if ( dp[i][count] != -1 ) return dp[i][count];
        if ( s[i] == '(' ) return dp[i][count] = f ( i + 1 , count + 1 , s , dp );
        if ( s[i] == ')' ) return dp[i][count] = f ( i + 1 , count - 1 , s , dp );
        return dp[i][count] = f ( i + 1 , count + 1 , s , dp ) || f ( i + 1 , count - 1 , s , dp ) || f ( i + 1 , count , s , dp );
    }
    bool checkValidString(string s) {
         int n = s.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
         return f ( 0 , 0 , s , dp );
    }
};