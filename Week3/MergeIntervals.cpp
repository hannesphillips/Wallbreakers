class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        if(intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end()); // Sort on start points
        
        vector<int> t;
        vector<vector<int>> res;
        
        t.push_back(intervals[0][0]);
        t.push_back(intervals[0][1]);
        
        /* If interval overlaps (endpoint >= startpoint), consolidate
        Verify new endpoint > old endpoint
        When overlap ends, push to result, reset */
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= t[1])
                t[1] = max(intervals[i][1], t[1]);
            else {
                res.push_back(t);
                t[0] = intervals[i][0];
                t[1] = intervals[i][1];
            }
        }
        res.push_back(t);
        return res;
    }
};