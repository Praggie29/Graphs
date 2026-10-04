class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int stepsToExit = 0;
        queue<pair<int,int>>q;
        int a = entrance[0];
        int b = entrance[1];
        q.push({a,b});
        int stepsToReachEntrance = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[a][b] = 1;
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        while(!q.empty()) {
           int size = q.size();
           while ( size-- ) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
             if ( (row == 0 || row == n - 1 || col == 0 || col == m - 1 ) && ( row != entrance[0] || col != entrance[1] ) ) return stepsToReachEntrance;
            for ( int i = 0 ; i < 4 ; i ++ ) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if ( nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
           }
           stepsToReachEntrance++;
        }
        return -1;
    }
};