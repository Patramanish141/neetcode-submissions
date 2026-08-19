class Solution {
public:
    vector<vector<string>> result;
    bool isSafe(int row, int col, int n, vector<string> &board){//returns is the queen safe here to place

        //Vertical Upwards Check
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }

        //Horizontal Left Check
        for(int j=0; j<col; j++){
            if(board[row][j] == 'Q') return false;
        }

        //Left Upwards Diagonal Check
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        
        //Right Upawards Diagonal Check
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueens(vector<string> &board, int n, int row){
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(row, j, n, board)){
                board[row][j] = 'Q';
                nQueens(board, n, row+1);
                board[row][j] = '.';
            }
        }        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        nQueens(board, n, 0);
       
        return result;
    }
};
