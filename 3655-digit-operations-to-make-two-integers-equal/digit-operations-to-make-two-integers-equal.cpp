class Solution {
public:
    int minOperations(int n, int m) {
        vector<bool> isPrime(10000, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p < 10000; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i < 10000; i += p)
                    isPrime[i] = false;
            }
        }

        if (isPrime[n] || isPrime[m]) return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minCost(10000, INT_MAX);
        pq.push({n, n});
        minCost[n] = n;

        while ( !pq.empty() ) {
            int sum = pq.top().first;
            int value = pq.top().second;
            pq.pop();

            if ( value == m ) return sum;
            if ( sum > minCost[value] ) continue;

            string s = to_string(value);
            
            for (int i = 0; i < s.length(); i++) {
                char original = s[i];
                if (original < '9') {
                    s[i] = original + 1;
                    int v = stoi(s);
                    if (!isPrime[v]) {
                        int newCost = sum + v;
                        if (newCost < minCost[v]) {
                            minCost[v] = newCost;
                            pq.push({newCost, v});
                        }
                    }
                }
                if (original > '0') {
                    s[i] = original - 1;
                    int v = stoi(s);
                    if (!isPrime[v]) {
                        int newCost = sum + v;
                        if (newCost < minCost[v]) {
                            minCost[v] = newCost;
                            pq.push({newCost, v});
                        }
                    }
                }
                
                s[i] = original; 
            }
        }
        
        return -1;
    }
};