class Solution {
public:
    void dfs(int n, int m, int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[row][col] = true;

        // if(row == 0 || row == n-1 || col == 0 || col == m-1) return 1;

        //top
        if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == '1'){
            dfs(n, m, row-1, col, grid, vis);
        }
        //right
        if(col+1 < m && !vis[row][col+1] && grid[row][col+1] == '1'){
            dfs(n, m, row, col+1, grid, vis);
        }
        //bottom
        if(row+1 < n && !vis[row+1][col] && grid[row+1][col] == '1'){
            dfs(n, m, row+1, col, grid, vis);
        }
        //left
        if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == '1'){
            dfs(n, m, row, col-1, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(n, m, i, j, grid, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};
