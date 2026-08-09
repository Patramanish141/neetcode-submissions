class Solution {
public:
    //Memoization Building
    int solve(int n, int m, int row, int col, vector<vector<int>> &dp){

        if(row >=n || col >= m) return 0;
        if(row == n-1 && col == m-1) return 1;

        if(dp[row][col] != -1 ) return dp[row][col];

        int val1 = solve(n, m, row, col+1, dp);
        int val2 = solve(n, m, row+1, col, dp);

        return dp[row][col] = val1+val2;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, 0, 0, dp);
    }
};
