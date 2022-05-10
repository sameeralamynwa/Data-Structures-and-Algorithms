class Solution {
public:
    int distanceFromOrigin(vector <int> &p){
        return p[0] * p[0] + p[1] * p[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set <pair <int, int> > kClosestSoFar;
        for(int i = 0; i < (int) points.size(); ++i){
            kClosestSoFar.insert({distanceFromOrigin(points[i]), i});
            if(kClosestSoFar.size() > k){
                kClosestSoFar.erase(--kClosestSoFar.end());
            }
        }
        vector <vector <int> > kClosest;
        for(pair <int, int> p : kClosestSoFar){
            kClosest.push_back(points[p.second]);
        }
        return kClosest;
    }
};
