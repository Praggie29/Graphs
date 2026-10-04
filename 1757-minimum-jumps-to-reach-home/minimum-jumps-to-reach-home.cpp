class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>mpp(forbidden.begin(),forbidden.end());
        int max_val = x;
        for (int num : forbidden) {
            max_val = max(max_val, num);
        }
        int limit = max_val + a + b;
        vector<vector<int>>vis(limit+1,vector<int>(2,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        int steps = 0;
        vis[0][0] = 0;
        while (!q.empty()) {
            int n = q.size();
            while ( n-- ) {
                int idx = q.front().first;
                int status = q.front().second;
                q.pop();
                if ( idx == x ) return steps;
                int forward = idx + a;
                if ( forward <= limit && mpp.find(forward) == mpp.end() && vis[forward][0] == 0) {
                    q.push({forward,0});
                    vis[forward][0] = 1;
                }
                int backward = idx - b;
                if ( status == 0 && backward >= 0 && mpp.find(backward) == mpp.end() && vis[backward][1] == 0) {
                    q.push({backward,1});
                    vis[backward][1] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};