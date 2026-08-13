//MST? => no beacuse here graph is directed
//Djikstra => perfect for here(min dist from src to all nodes)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//dist[v], v
        vector<int> dist(n+1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            for(auto &neighbor : adj[u]){
                int v = neighbor.first;
                int wt = neighbor.second;

                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(dist[i], maxTime);
        }

        return maxTime;
    }
};
