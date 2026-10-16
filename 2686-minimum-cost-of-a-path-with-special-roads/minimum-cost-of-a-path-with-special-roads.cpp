class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
       set<pair<int, int>> visited;

        pq.push({0,{start[0],start[1]}});
        
        while(!pq.empty()) {
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if ( x == target[0] && y == target[1] ) return dis;

            if (visited.count({x, y})) continue;
            visited.insert({x, y});

            int directCost = dis + abs(target[0] - x) + abs(target[1] - y);
            pq.push({directCost, {target[0], target[1]}});

            for (auto& road : specialRoads) {
                int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], cost = road[4];
                int roadCost = dis + abs(x1 - x) + abs(y1 - y) + cost;
                pq.push({roadCost, {x2, y2}});
            }
        }
        return -1;
    }
};  