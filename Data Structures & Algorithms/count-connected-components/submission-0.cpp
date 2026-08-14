class Solution {
public:
    int count = 0;

    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;

        for(int v : adj[node]){
            if(!vis[v]) dfs(v, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                count++;
            }
        }
        
        return count;
    }
};
