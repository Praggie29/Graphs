class Solution {
public:
    void dfs ( int i ,  int j , vector<vector<char>>& grid , vector<vector<int>>& visited ) {
        int n = grid.size();
        int m = grid[0].size();
        if ( i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || grid[i][j] == '0' ) return;
        visited[i][j] = 1;
        dfs ( i + 1 , j , grid , visited );
        dfs ( i - 1 , j , grid , visited );
        dfs ( i , j + 1 , grid , visited );
        dfs ( i , j - 1 , grid , visited );
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>adjacencyList(n);
        int islandsCnt = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j ++ ) {
            if ( !visited[i][j] && grid[i][j] == '1') {
                islandsCnt++;
                dfs ( i , j , grid , visited );
            }
            }
        }
        return islandsCnt;
    }
};