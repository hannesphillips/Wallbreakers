class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        
        int arw = 1;
        sort(points.begin(), points.end());
        int right_pt = points[0][1];
        
        /* Check for overlap based on start point < end point of
        current balloon. Valid by sorting balloons on start point.
        If end point of a balloon in range < current end point,
        reduce viable range */
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > right_pt) {
                arw++;
                right_pt = points[i][1];
            }
            else if(points[i][1] < right_pt)
                right_pt = points[i][1];
        }
        return arw;
    }
};