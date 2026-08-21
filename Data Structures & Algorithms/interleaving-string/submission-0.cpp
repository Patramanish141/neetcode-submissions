class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool result = false;

        // try taking next char from s1, only if s1 has chars left
        if(i < s1.size() && s1[i] == s3[i+j]){
            result = result || solve(s1, s2, s3, i+1, j, dp);
        }

        // try taking next char from s2, only if s2 has chars left
        // check BOTH possibilities (not else-if) since either could work
        if(!result && j < s2.size() && s2[j] == s3[i+j]){
            result = result || solve(s1, s2, s3, i, j+1, dp);
        }

        return dp[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));//dp[i][j] =>taking i chars of s1 and j chars of s2 can we make i+j chars of s3

        return solve(s1, s2, s3, 0, 0, dp);
    }
};
