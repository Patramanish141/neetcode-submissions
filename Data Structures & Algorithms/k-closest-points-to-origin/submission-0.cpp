struct ComparePair{
    bool operator () (const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;//<distSq, idx>
        vector<vector<int>> ans;
        
        for(int i = 0; i<points.size(); i++){
            int distSq = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push(make_pair(distSq, i));
        }

        for(int i=0; i<k; i++){
            int idx = pq.top().second;
            ans.push_back(points[idx]);

            pq.pop();
        }
        return ans;
    }
};