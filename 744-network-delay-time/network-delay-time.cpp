class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;
        vector<vector<pair<int, int>>> adj(n+1);
        for ( int i = 0 ; i < times.size() ; i ++ ) {
            int source = times[i][0];
            int target = times[i][1];
            int wt = times[i][2];
            adj[source].push_back({target,wt});
        }
        dist[k] = 0;
        st.insert({0,k});
        while ( !st.empty() ) {
            auto it = *(st.begin());
            int dis = it.first;
            int nodeVal = it.second;
            st.erase(it);
            for ( auto &it : adj[nodeVal] ) {
                int adjNode = it.first;
                int adjWt = it.second;
                if (dis + adjWt < dist[adjNode]) {
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }
                dist[adjNode] = dis + adjWt;
                st.insert({dist[adjNode],adjNode});
                }
            }
        }
        int ans = 0;
        for ( int i = 1 ; i <= n ; i ++ ) {
            ans = max ( ans , dist[i] );
        }
        return ans == INT_MAX ? -1 : ans;
    }
};