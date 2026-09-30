class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int maxElev = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (r == n - 1 && c == n - 1) {
                return maxElev;
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(maxElev, grid[nr][nc]), nr, nc});
                }
            }
        }
        
        return -1;
    }
};