//BFS Kahn's algorithm

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        //inDeg Calculation
        vector<vector<int>> inDeg(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int currCell = matrix[i][j];

                //top
                if(i-1>=0 && currCell > matrix[i-1][j]){
                    inDeg[i][j]++;
                }
                //right
                if(j+1<m && currCell > matrix[i][j+1]){
                    inDeg[i][j]++;
                }
                //bottom
                if(i+1<n && currCell > matrix[i+1][j]){
                    inDeg[i][j]++;
                }
                //left
                if(j-1>=0 && currCell > matrix[i][j-1]){
                    inDeg[i][j]++;
                }
            }
        }

        //Initating the queue
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(inDeg[i][j] == 0) q.push({i, j});
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, 1));//dist[i][j] => longest dist of path ending at i, j

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            int currCell = matrix[row][col];

            //top
            if(row-1>=0 && matrix[row-1][col] > currCell){
                dist[row-1][col] = max(dist[row-1][col], 1 + dist[row][col]);
                inDeg[row-1][col]--;
                if(inDeg[row-1][col] == 0) q.push({row-1, col});
            }
            //right
            if(col+1<m && matrix[row][col+1] > currCell){
                dist[row][col+1] = max(dist[row][col+1], 1 + dist[row][col]);
                inDeg[row][col+1]--;
                if(inDeg[row][col+1] == 0) q.push({row, col+1});
            }
            //bottom
            if(row+1<n && matrix[row+1][col] > currCell){
                dist[row+1][col] = max(dist[row+1][col], 1 + dist[row][col]);
                inDeg[row+1][col]--;
                if(inDeg[row+1][col] == 0) q.push({row+1, col});
            }
            //left
            if(col-1>=0 && matrix[row][col-1] > currCell){
                dist[row][col-1] = max(dist[row][col-1], 1 + dist[row][col]);
                inDeg[row][col-1]--;
                if(inDeg[row][col-1] == 0) q.push({row, col-1});
            }
        }

        //Have the dist 2D array build..just have to form answer
        int maxLen = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxLen = max(maxLen, dist[i][j]);
            }
        }

        return maxLen;

    }
};
