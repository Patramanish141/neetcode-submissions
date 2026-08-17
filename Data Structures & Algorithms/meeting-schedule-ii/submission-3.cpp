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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;

        for(auto &i : intervals){
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int cnt_rooms = 0, min_rooms = 0;
        int s = 0, e = 0;

        while(s < starts.size()){
            if(starts[s] < ends[e]){
                cnt_rooms++;
                min_rooms = max(min_rooms, cnt_rooms);
                s++;
            } else {
                cnt_rooms--;
                e++;
            }
        }

        return min_rooms;



    }
};
