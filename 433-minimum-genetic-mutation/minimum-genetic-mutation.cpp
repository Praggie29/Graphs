class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        
        if (st.find(endGene) == st.end()) return -1;
        
        queue<string> q;
        q.push(startGene);
        
        int steps = 0;
        vector<char> choices = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                string curr = q.front();
                q.pop();
                
                if (curr == endGene) return steps;
                
                for (int i = 0; i < curr.length(); ++i) {
                    char original = curr[i];
                    
                    for (char ch : choices) {
                        curr[i] = ch;
                        
                        if (st.find(curr) != st.end()) {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    
                    curr[i] = original;
                }
            }
            steps++;
        }
        
        return -1;
    }
};