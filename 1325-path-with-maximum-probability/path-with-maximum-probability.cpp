class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        vector<vector<pair<int, double>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            adjacencyList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjacencyList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double dis = pq.top().first;
            int nodeVal = pq.top().second;
            pq.pop();

            if (dis < dist[nodeVal]) continue;

            for (auto& neighbor : adjacencyList[nodeVal]) {
                int nbrNode = neighbor.first;
                double prob = neighbor.second;

                if (dis * prob > dist[nbrNode]) {
                    dist[nbrNode] = dis * prob;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        return dist[end_node];
    }
};