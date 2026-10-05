class Solution {
public:
    int getReachableCount(int S, int n, unordered_map<int, vector<pair<int, int>>>& adj, int distanceThreshold) {
        queue<pair<int, int>> q; 
        vector<int> dist(n, INT_MAX);              

        dist[S] = 0;
        q.push({0, S});

        while (!q.empty()) {
            int d = q.front().first;
            int node = q.front().second;
            q.pop();

            if (d > dist[node]) continue;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i != S && dist[i] <= distanceThreshold) {
                count++;
            }
        }

        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int cityWithFewestReachable = -1;
        int minReachableCount = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int reachableCount = getReachableCount(i, n, adj, distanceThreshold);
            if (reachableCount <= minReachableCount) {
                minReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }

        return cityWithFewestReachable;
    }
};