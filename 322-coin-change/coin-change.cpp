class Solution {
public:
    int f(int idx, int t, vector<int> &nums, vector<vector<int>> &dp){
        if(t == 0) return 0;
        if(idx == 0){
            if(t % nums[0] == 0) return t / nums[0];
            else return 1e9;
        }
        if(dp[idx][t] != -1) return dp[idx][t];
        int notTake = f(idx-1, t, nums, dp);
        int take = 1e9;
        if(nums[idx] <= t)
            take = 1 + f(idx, t-nums[idx], nums, dp);
        return dp[idx][t] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};