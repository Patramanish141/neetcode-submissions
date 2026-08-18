class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        vector<pair<int, string>> &v = m[key];
        int lo = 0, hi = v.size() - 1;
        int resultIdx = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(v[mid].first <= timestamp){
                resultIdx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return resultIdx == -1 ? "" : v[resultIdx].second;
        
    }
};
