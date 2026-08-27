class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //left top to right bottom
        //Basically have to find a route where the max val is smallest among all route maximums
        int n = grid.size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;//{timeSoFar, r, c}

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int t=curr[0], r = curr[1], c = curr[2];

            if(r == n-1 && c == n-1) return t;

            for(auto &dir : directions){
                int neiR = r + dir[0], neiC = c + dir[1];
                if(neiR < 0 || neiR == n || neiC < 0 || neiC == n || vis[neiR][neiC]) continue;

                vis[neiR][neiC] = true;
                minHeap.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }
        }

        return n*n;
    }
};
