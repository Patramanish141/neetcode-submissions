class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &recPath,  stack<int> &s){
        vis[src] = true;
        recPath[src] = true;
        for(int &v : adj[src]){
            if(!vis[v]){
                if(isCycle(v, vis, adj, recPath, s)){
                    return true;
                };
            } else {
                if(recPath[v]){
                    return true;
                }
            }
        }
        s.push(src);
        recPath[src] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<vector<int>> adj(V);

        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> recPath(V, false), vis(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, vis, adj, recPath, s)) return {};
            }
        }

        vector<int> order;
        while(!s.empty()){
            order.push_back(s.top());
            s.pop();
        }

        return order;
    }
};
