class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector <int> &a, const vector <int> &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int maxRightEnd = 0, overlappingIntervals = 0;
        for(int i = 0; i < (int) intervals.size(); ++i){
            if(intervals[i][1] <= maxRightEnd){
                overlappingIntervals++;
            }
            maxRightEnd = max(maxRightEnd, intervals[i][1]);
        }
        return (int) intervals.size() - overlappingIntervals;
    }
};
