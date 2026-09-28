class Solution {
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                long long edgWt = it.second;

                if (dis + edgWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgWt;
                    pq.push({dis + edgWt, adjNode});
                    ways[adjNode] = ways[node];
                } 
                else if (dis + edgWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % M;
                }
            }
        }

        return ways[n - 1] % M;
    }
};