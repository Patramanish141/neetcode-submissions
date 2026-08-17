class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sorting activities on end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int count = 1;
        int currEndTime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= currEndTime){
                count++;
                currEndTime = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};