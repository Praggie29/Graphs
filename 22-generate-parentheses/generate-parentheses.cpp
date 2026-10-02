class Solution {
public:
    bool isValid ( string &s ) {
        stack<int>st;
        for ( char ch : s ) {
            if ( ch == '(' ) {
                st.push(ch);
            }
            else {
                if ( st.empty() ) return false;
                char topChar = st.top();
                if ( topChar == '(' && ch == ')') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
    void generate ( vector<string>&ans , string &curr , int totalSize ) {
       if ( curr.size() == totalSize ) {
           if ( isValid(curr)) ans.push_back(curr);
           return;
       }
       curr.push_back('(');
       generate(ans,curr,totalSize);
       curr.pop_back();
       curr.push_back(')');
       generate(ans,curr,totalSize);
       curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int totalSize = 2 * n;
        string curr = "";
        generate(ans,curr,totalSize);
        return ans;
    }
};