//Just circular arrangement of house robber-I Question
class Solution {
public:
    int helper(vector<int> nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        return max(helper(vector<int>(nums.begin() + 1, nums.end())),
                        helper(vector<int>(nums.begin(), nums.end() - 1)));
    }
};
