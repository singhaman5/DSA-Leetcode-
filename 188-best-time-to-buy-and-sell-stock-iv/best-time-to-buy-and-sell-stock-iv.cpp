class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> cur(2, vector<int>(k+1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { 
                        cur[buy][cap] = max(
                            after[0][cap], 
                            -prices[ind] + after[1][cap]
                        );
                    }
                    else { 
                        cur[buy][cap] = max(
                            after[1][cap],
                            prices[ind] + after[0][cap - 1]
                        );
                    }
                }
            }
            after = cur;
        }
        return after[0][k]; 
    }
};