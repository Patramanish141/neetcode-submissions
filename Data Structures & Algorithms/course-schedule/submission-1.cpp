class Solution {
public:
    bool isCycle(int src, vector<bool> &recPath, vector<bool> &vis, vector<vector<int>> &adj){
        vis[src] = true;
        recPath[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                if(isCycle(v, recPath, vis, adj)) return true;
            } else {
                if(recPath[v]) return true;
            }
        }

        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       //Directed graph
        int V = numCourses;
        vector<vector<int>> adj(V);

        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> recPath(V, false), vis(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, recPath, vis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
