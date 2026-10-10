class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        int maxDiff = 0;
        vector<int> diffs(n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diffs[i]);
        }
        vector<long long> count(maxDiff + 2, 0);
        for (int d : diffs) {
            count[d]++;
        }
        for (int d = maxDiff; d > 0 && totalK > 0; --d) {
            if (count[d] == 0) continue;
            long long take = min(totalK, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            totalK -= take;
        }
        long long ans = 0;
        for (int d = 1; d <= maxDiff; ++d) {
            if (count[d] > 0) {
                ans += count[d] * (1LL * d * d);
            }
        }
        
        return ans;
    }
};