class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(start);
        while ( !q.empty() ) {
            int size = q.size();
            while ( size-- ) {
               int valIdx = q.front();
               q.pop();
               if ( arr[valIdx] == 0 ) return true;
               if ( valIdx + arr[valIdx] < n && !visited[valIdx+arr[valIdx]] ) {
                   visited[valIdx+arr[valIdx]] = true;
                   q.push(valIdx+arr[valIdx]);
               }
               if ( valIdx - arr[valIdx] >= 0 && !visited[valIdx-arr[valIdx]]) {
                    visited[valIdx - arr[valIdx]] = true;
                   q.push(valIdx - arr[valIdx]);
               }
            }
        }
        return false;
    }
};