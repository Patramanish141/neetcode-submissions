class Solution {
public:
    //Memoization Building
    // int solve(int n, int m, int row, int col, vector<vector<int>> &dp){

    //     if(row >=n || col >= m) return 0;
    //     if(row == n-1 && col == m-1) return 1;

    //     if(dp[row][col] != -1 ) return dp[row][col];

    //     int val1 = solve(n, m, row, col+1, dp);
    //     int val2 = solve(n, m, row+1, col, dp);

    //     return dp[row][col] = val1+val2;
    // }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;
        for(int j=0; j<m; j++) dp[0][j] = 1;


        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};
