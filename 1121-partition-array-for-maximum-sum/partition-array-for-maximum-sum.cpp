class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Tabulation Code -: 
        int n = arr.size();
        vector<int> dp(n+2,0);
        for(int i = n-1; i>=0; i--){
            int maxAns = INT_MIN, len = 0, maxi = INT_MIN;
            for(int j = i; j<min(i+k,n); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};