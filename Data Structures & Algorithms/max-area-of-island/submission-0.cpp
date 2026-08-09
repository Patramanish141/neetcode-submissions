class Solution {
public:
    //dfs will return size of every islands
    int dfs(int n, int m, int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        vis[row][col] = true;
        int size = 0;

        //top
        if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == 1){
            size += dfs(n, m, row-1, col, vis, grid);
        }
        //right
        if(col+1 < m && !vis[row][col+1] && grid[row][col+1] == 1){
            size += dfs(n, m, row, col+1, vis, grid);
        }
        //bottom
        if(row+1 < n && !vis[row+1][col] && grid[row+1][col] == 1){
            size += dfs(n, m, row+1, col, vis, grid);
        }
        //left
        if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == 1){
            size += dfs(n, m, row, col-1, vis, grid);
        }


        return size + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int maxSize = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int size = dfs(n, m, i, j, vis, grid);
                    maxSize = max(size, maxSize);
                }
            }
        }

        return maxSize;
    }
};
