class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        q.push({0, 0, k});

        vector<vector<int>> visited(n, vector<int>(m, -1));
        visited[0][0] = k;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        int stepsToReachEnd = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                vector<int> qVal = q.front();
                q.pop();

                int row = qVal[0];
                int col = qVal[1];
                int kVal = qVal[2];

                if (row == n - 1 && col == m - 1) return stepsToReachEnd;

                for (int d = 0; d < 4; d++) {
                    int nr = row + dr[d];
                    int nc = col + dc[d];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        int nextK = kVal;
                        if ( grid[nr][nc] == 1 ) nextK--;
                        if (nextK >= 0 && nextK > visited[nr][nc]) {
                            visited[nr][nc] = nextK;
                            q.push({nr, nc, nextK}); 
                        }
                    }
                }
            }
            stepsToReachEnd++;
        }

        return -1;
    }
};