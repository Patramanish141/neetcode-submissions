class Solution {
public:
    bool dfs(int node, int par, vector<bool> &vis, vector<vector<int>> &adj){
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
    bool validTree(int n, vector<vector<int>>& edges) {
        //simple cycle detection question
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (dfs(0, -1, vis, adj)) return false;
        for(bool v : vis) if(!v) return false;
        return true;
    }
};
