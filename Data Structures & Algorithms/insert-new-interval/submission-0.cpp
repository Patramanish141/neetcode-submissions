class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int l = 0, r = n - 1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(intervals[mid][0] < target) l = mid + 1;
            else r = mid - 1;
        }
        //l is the idx at which newInteral is supposed to be placed

        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto &i : intervals){
            int st = i[0], end = i[1];
            int lastEnd = res.back()[1];

            if(st <= lastEnd){
                res.back()[1] = max(end, lastEnd);
            } else {
                res.push_back({st, end});
            }
        }

        return res;
    }
};
