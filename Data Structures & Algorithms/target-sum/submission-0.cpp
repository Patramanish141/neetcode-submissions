class Solution {
public:
    int sum;
    int solve(vector<int> &nums, int target, vector<vector<int>> &dp, int idx, int currSum){
        if(idx == nums.size()) return currSum == target ? 1 : 0;
        if(dp[idx][currSum+sum] != -1) return dp[idx][currSum+sum];

        dp[idx][currSum+sum] = solve(nums, target, dp, idx+1, currSum+nums[idx]) +
                        solve(nums, target, dp, idx+1, currSum-nums[idx]);

        return dp[idx][currSum+sum];//to not let dp[][-ve] we are doing dp[][currSum+sum]

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(target > sum || target < -sum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*sum+1, -1));
        //no. of ways to achieve j if we take i elements

        return solve(nums, target, dp, 0, 0);

    }
};
