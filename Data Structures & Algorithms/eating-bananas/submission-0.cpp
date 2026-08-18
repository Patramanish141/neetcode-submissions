class Solution {
public:
    typedef long long ll;
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int m = *max_element(piles.begin(), piles.end());
        if(h == n){
            return m;
        }

        //upper bound of k is m and lower bound is 1;
        int l = 1, r = m, res = r;
        while(l <= r){
            int k = l + (r-l)/2;//try k in piles

            ll totalTime = 0;
            for(int p : piles){
                totalTime += ceil((double)p / k);
            }

            if(totalTime <= h){
                res = k;
                r = k-1;
            } else {
                l = k+1;
            }
        }

        return res;

    }
};
