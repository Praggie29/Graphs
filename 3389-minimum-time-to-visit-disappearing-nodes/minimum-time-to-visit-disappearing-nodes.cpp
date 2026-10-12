class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int length = edge[2];
            adj[u].push_back({v, length});
            adj[v].push_back({u, length});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> ans(n, -1);
        pq.push({0, 0});
        ans[0] = 0;

        while (!pq.empty()) {
            auto [curr_time, u] = pq.top();
            pq.pop();
            if (curr_time > ans[u]) continue;
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                int arrival_time = curr_time + weight;
                if (arrival_time < disappear[v]) {
                    if (ans[v] == -1 || arrival_time < ans[v]) {
                        ans[v] = arrival_time;
                        pq.push({arrival_time, v});
                    }
                }
            }
        }

        return ans;
    }
};