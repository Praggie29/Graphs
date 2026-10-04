class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        int stepsToReachGoal = 0;
        vector<bool>visited(10001,false);
        queue<int>q;
        q.push(start);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int val = q.front();
                q.pop();
                for ( int i = 0 ; i < n ; i ++ ) {
                    int add = val + nums[i];
                    int sub = val - nums[i];
                    int bitwiseXOR = val ^ nums[i];
                    if ( add == goal || sub == goal || bitwiseXOR == goal ) return stepsToReachGoal + 1 ;
                    if ( add >= 0 && add <= 1000 && !visited[add] ) {
                        visited[add] = true;
                        q.push(add);
                    }
                    if ( sub >= 0 && sub <= 1000 && !visited[sub] ) {
                        visited[sub] = true;
                        q.push(sub);
                    }
                    if ( bitwiseXOR >= 0 && bitwiseXOR <= 1000 && !visited[bitwiseXOR] ) {
                        visited[bitwiseXOR] = true;
                        q.push(bitwiseXOR);
                    }
                }
                
            }
            stepsToReachGoal++;
        }
        return -1;
    }
};