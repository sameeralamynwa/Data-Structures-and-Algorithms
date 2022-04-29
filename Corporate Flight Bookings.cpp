class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector <int> cumulativeSum(n, 0);
        for(vector <int> &v : bookings){
            cumulativeSum[--v[0]] += v[2];
            if(v[1] < n){
                cumulativeSum[v[1]] -= v[2];
            }
        }
        for(int i = 1; i < n; ++i){
            cumulativeSum[i] += cumulativeSum[i - 1];
        }
        return cumulativeSum;
    }
};
