/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            return x.start < y.start;
        });

        for(int i=0; i + 1 < intervals.size(); i++){
            if(intervals[i].end > intervals[i+1].start) return false;
        }

        return true;
    }
};
