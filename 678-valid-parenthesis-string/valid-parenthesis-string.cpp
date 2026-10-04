class Solution {
public:
   bool f(int i,string &s,int n,int cnt,vector<vector<int>>&dp){
        if(cnt<0) return false;
        if(i==n){
            return cnt==0;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        if(s[i]=='(') return dp[i][cnt]=f(i+1,s,n,cnt+1,dp);
        if(s[i]==')') return dp[i][cnt]=f(i+1,s,n,cnt-1,dp);
        return dp[i][cnt]=f(i+1,s,n,cnt+1,dp) || f(i+1,s,n,cnt-1,dp) || f(i+1,s,n,cnt,dp);
    }
    bool checkValidString(string s) {
       int n=s.size();
       int cnt=0;
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return f(0,s,n,cnt,dp); 
    }
};