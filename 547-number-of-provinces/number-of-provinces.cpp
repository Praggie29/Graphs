class Solution {
public:
    void dfs ( int node ,  vector<vector<int>>&adjacencyList , vector<int>& visited ) {
        visited[node] = 1;
        for ( auto &it : adjacencyList[node] ) {
            if ( !visited[it] ) {
                dfs ( it , adjacencyList , visited );
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provincesCnt = 0;
        int n = isConnected.size();
        vector<vector<int>>adjacencyList(n);
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( isConnected[i][j] == 1 && i != j ) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( !visited[i] ) {
                provincesCnt++;
                dfs ( i , adjacencyList , visited );
            }
        }
        return provincesCnt;
    }
};