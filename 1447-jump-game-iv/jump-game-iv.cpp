class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if ( n == 1 ) return 0;
        unordered_map <int,vector<int>> mpp;
        for ( int i = 0 ; i < n ; i ++ ) {
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while ( !q.empty()) {
            int size = q.size();
            while ( size-- ) {
               int valIdx = q.front();
               q.pop();
               if ( valIdx == n - 1 ) return steps;
               if ( valIdx - 1 >= 0 && !visited[valIdx-1] ) {
                visited[valIdx-1] = true;
                q.push(valIdx-1);
               }
               if ( valIdx + 1 < n && !visited[valIdx+1] ) {
                visited[valIdx+1] = true;
                q.push(valIdx + 1);
               }
               for ( auto it : mpp[arr[valIdx]] ) {
                   if ( !visited[it] ) {
                       visited[it] = true;
                       q.push(it);
                   }
               }
               mpp[arr[valIdx]].clear();
            }
            steps++;
        }
        return steps;
    }
};