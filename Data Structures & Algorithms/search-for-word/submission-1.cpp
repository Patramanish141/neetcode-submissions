class Solution {
public:
    int n, m;
    bool dfs(int row, int col, int idx, vector<vector<char>> board, string word){
        if(idx == word.size()) return true;//found the last character

        if(row<0 || col<0 || row>=n || col>=m || board[row][col] != word[idx] || board[row][col] == '#') return false;

        board[row][col] = '#';
        bool res = dfs(row-1, col, idx+1, board, word) ||
                    dfs(row, col+1, idx+1, board, word) ||
                    dfs(row+1, col, idx+1, board, word) ||
                    dfs(row, col-1, idx+1, board, word);

        board[row][col] = word[idx];
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(i, j, 0, board, word)){
                    return true;
                }
            }
        }

        return false;
    }
};
