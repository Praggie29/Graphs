class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        string initialLock = "0000";
        queue<string>q;
        q.push(initialLock);
        int steps = 0;
        if (st.find("0000") != st.end()) return -1;
        if ("0000" == target) return 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
               string lock = q.front();
               q.pop();
               if ( lock == target ) return steps;
               for ( int i = 0 ; i < 4 ; i ++ ) {
                   char ch = lock[i];
                   char inc = ch == '9' ? '0' : ch + 1;
                   lock[i] = inc;
                   if ( st.find(lock) == st.end() ) {
                     q.push(lock);
                     st.insert(lock);
                   }
                   lock[i] = ch;
                   char dec = ch == '0' ? '9' : ch - 1;
                   lock[i] = dec;
                   if ( st.find(lock) == st.end() ) {
                     q.push(lock);
                     st.insert(lock);
                   }
                   lock[i] = ch;
               }
            }
            steps++;
        }
        return -1;
    }
};