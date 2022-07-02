class Solution {
private:
    static const int mod = 1e9 + 7;
    
public:
    int computeMaxGap(vector <int> &positions, int length){
        sort(positions.begin(), positions.end());
        int maxGap = max(*positions.begin(), length - positions.back());
        for(int i = 0; i + 1 < (int) positions.size(); ++i){
            maxGap = max(maxGap, positions[i + 1] - positions[i]);
        }
        return maxGap;
    }

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (long long) computeMaxGap(horizontalCuts, h) * computeMaxGap(verticalCuts, w) % mod;
    }
};
