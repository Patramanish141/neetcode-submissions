class Solution {
public:
    bool dfs(int node, int par, vector<bool> &vis, vector<vector<int>>& adj){
        vis[node] = true;

        for(int v : adj[node]){
            if(!vis[v]){
                if(dfs(v, node, vis, adj)) return true;
            } else {
                if(par != v) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        
        vector<vector<int>> adj(n+1);

        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n+1, false);

            if(dfs(u, -1, vis, adj)){
                return {u, v};
            }
        }
        return {};
    }
};
