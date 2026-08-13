class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for(int i=0; i<=k; i++){
            vector<int> tempPrices = prices;
            
            for(auto &flight : flights){
                int s = flight[0], d = flight[1], p = flight[2];

                if(prices[s] == INT_MAX) continue;

                if(prices[s] + p < tempPrices[d]){
                    tempPrices[d] = prices[s] + p;
                }
            }

            prices = tempPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
