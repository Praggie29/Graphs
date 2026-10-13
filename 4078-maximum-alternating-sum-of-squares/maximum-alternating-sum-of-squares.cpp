class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>sq;
        for(int i=0;i<n;i++){
            sq.push_back(nums[i]*nums[i]);
        }
        sort(sq.begin(),sq.end());
        int half=n/2;
        long long a=0;
        for(int i=0;i<half;i++){
            a+=sq[i];
        }
        long long b=0;
        for(int i=half;i<n;i++){
            b+=sq[i];
        }
        return abs(a-b);
    }
};