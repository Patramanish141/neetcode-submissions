class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //unbounded knapsack

        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;
        for(int j=1; j<=amount; j++){
            for(int coin : coins){
                if(coin <= j && dp[j-coin] != INT_MAX) dp[j] = min(dp[j], dp[j-coin]+1);
            }
            
        }

        return dp[amount] == -1 ? -1 : (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};
