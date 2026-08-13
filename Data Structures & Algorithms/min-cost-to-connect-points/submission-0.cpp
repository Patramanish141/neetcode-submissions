class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //simple djisktra?
        int n = points.size();

        //Min Heap(dist[v], v)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> mst(n, false);

        int src = 0;
        pq.push({0, 0});
        int minCost = 0;

        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                minCost += cost;

                //traversing for every neighbor of u(here all other points are neighbor of u)
                for(int v=0; v<n; v++){
                    if(u != v){
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push({wt, v});
                    }
                }
            }
        }

        return minCost;


    }
};
