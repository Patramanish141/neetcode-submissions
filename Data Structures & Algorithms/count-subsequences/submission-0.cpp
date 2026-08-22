class Solution {
public:
    int dfs(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = dfs(s, t, i+1, j, dp);
        if(s[i] == t[j]){
            res += dfs(s, t, i+1, j+1, dp);
        }

        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        if(m > n) return 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return dfs(s, t, 0, 0, dp);
    }
};
