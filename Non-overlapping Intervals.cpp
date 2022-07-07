class Solution {
public:
    int eraseOverlapIntervals(vector <vector <int> > &intervals) {
        sort(intervals.begin(), intervals.end(), [] (const vector <int> &a, const vector <int> &b){
            return a.back() == b.back() ? *a.begin() < *b.begin() : a.back() < b.back();
        });
        int disjointIntervals = 0, maxEnd;
        for(int i = 0; i < (int) intervals.size(); ++i){
            if(i == 0 or *intervals[i].begin() >= maxEnd){
                ++disjointIntervals;
                maxEnd = i == 0 ? intervals[i].back() : max(maxEnd, intervals[i].back());
            }
        }
        return (int) intervals.size() - disjointIntervals;
    }
};
