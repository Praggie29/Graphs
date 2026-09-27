class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1||grid[n-1][m-1]==1) return -1;
        if(n==1) return 1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dist[0][0]=1;
        q.push({1,{0,0}});

        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
        
            for(int i=0;i<8;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                 if(nr==n-1&&nc==m-1) return dis+1;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==0&&dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    q.push({dis+1,{nr,nc}});
                }
            }
        }

        return -1;
    }
};