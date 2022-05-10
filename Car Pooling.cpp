class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxRightEnd = 0;
        for(vector <int> &v : trips){
            maxRightEnd = max(maxRightEnd, v.back());
        }
        vector <int> cumSum(maxRightEnd + 1);
        for(vector <int> &v : trips){
            cumSum[v[1]] += v[0];
            if(v[2] != maxRightEnd){
                cumSum[v[2] + 1] -= v[0];
            }
        }
        for(int i = 0; i <= maxRightEnd; ++i){
            if(i > 0){
                cumSum[i] += cumSum[i - 1];
            }
        }
        for(vector <int> &v : trips){
            cumSum[v.back()] -= v[0];
        }
        return *max_element(cumSum.begin(), cumSum.end()) <= capacity;
    }
};
