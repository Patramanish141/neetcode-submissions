class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //0/1 knapsack where we have to fill sum/2 using nums

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int W = sum/2;

        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][W] == W;

    }
};
