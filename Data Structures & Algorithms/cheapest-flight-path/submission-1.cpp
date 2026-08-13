class Info{
public:
    int u, cost, stops;

    Info(int u, int cost, int stops){
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(n, INT_MAX);

        vector<vector<pair<int, int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        dist[src] = 0;
        q.push(Info(src, 0, -1));

        while(!q.empty()){
            Info curr = q.front();
            q.pop();

            int cost = curr.cost;
            int stops = curr.stops;

            for(auto &p : adj[curr.u]){
                int v = p.first;
                int wt = p.second;

                if(cost + wt < dist[v] && stops+1 <= k){
                    dist[v] = cost + wt;
                    q.push(Info(v, dist[v], stops+1));
                }
            }     
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
