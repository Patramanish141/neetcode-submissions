class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort by ending time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(auto &i : intervals){
            int st = i[0];
            int end = i[1];
            int lastEnd = ans.back()[1];

            if(st <= lastEnd){
                ans.back()[1] = max(lastEnd, end);
            } else {
                ans.push_back({st, end});
            }
        }

        return ans;
        
    }
};
