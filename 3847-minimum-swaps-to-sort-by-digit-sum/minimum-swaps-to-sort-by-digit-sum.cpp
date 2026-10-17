class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>,int>>eles(n);
        for ( int i = 0 ; i < n ; i ++ ) {
            int num = nums[i];
            int sum = 0;
            while ( num ) {
                int rem = num % 10;
                sum += rem;
                num /= 10;
            }
            eles[i] = {{sum , nums[i]} , i };
        }
        sort(eles.begin(),eles.end());
        unordered_map <int,int> currPos;
        int numOfSwaps = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            currPos[nums[i]] = i;
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            int targetVal = eles[i].first.second;
            if ( nums[i] != targetVal ) {
                numOfSwaps++;
                int idx = currPos[targetVal];
                currPos[nums[i]] = idx;
                currPos[targetVal] = i;
                swap ( nums[i] , nums[idx] );
            }
        }
        return numOfSwaps;
    }
};