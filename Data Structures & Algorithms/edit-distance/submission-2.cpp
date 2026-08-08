class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // if(n == 0 && m != 0) return m;
        // if(n != 0 && m == 0) return n;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++) dp[i][0] = i;
            
        for(int j=1; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] != word2[j-1]){
                    int remove = dp[i-1][j];//last char of word1
                    int insert = dp[i][j-1];
                    int replace = dp[i-1][j-1];

                    dp[i][j] = 1 + min(remove, min(insert, replace));
                } else {
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
            }
        }

        return dp[n][m];
    }
};
