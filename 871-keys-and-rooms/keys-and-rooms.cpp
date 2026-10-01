class Solution {
public:
    void dfs ( int i , vector<vector<int>>& rooms , vector<int>&visited ) {
        visited[i] = 1;
        for ( int it : rooms[i] ) {
            if ( !visited[it] ) dfs ( it , rooms , visited );
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        dfs ( 0 , rooms , visited );
        for ( int i = 0 ; i < n ; i ++ ) if ( visited[i] == 0 ) return false;
        return true;
    }
};