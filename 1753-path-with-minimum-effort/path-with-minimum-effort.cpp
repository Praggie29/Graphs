class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
         int n = heights.size();
         int m = heights[0].size();
         vector<vector<int>>dist(n,vector<int>(m,1e9));
         dist[0][0] = 0;
         pq.push({0,{0,0}});
         vector<int>dr = {-1,0,1,0};
         vector<int>dc = {0,1,0,-1};
         while ( !pq.empty() ) {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if ( row == n -1 && col == m - 1 ) return diff;
            for ( int i = 0 ; i < 4 ; i ++ ) {
                int newR = row + dr[i];
                int newC = col + dc[i];
                if ( newR >= 0 && newR < n && newC >= 0 && newC < m ) {
                    int newDiff = max ( abs(heights[row][col] - heights[newR][newC]) , diff );
                    if ( newDiff < dist[newR][newC] ) {
                        dist[newR][newC] = newDiff;
                        pq.push({dist[newR][newC] , {newR,newC}});
                    }
                }
            }
         }
         return 0;
    }
};