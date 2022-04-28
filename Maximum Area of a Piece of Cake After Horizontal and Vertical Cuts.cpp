class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.insert(horizontalCuts.begin(), h);
        
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.begin(), w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long maxArea = 0;
        int maxWidth = 0;
        
        for(int i = 0; i + 1 < verticalCuts.size(); ++i){
            maxWidth = max(maxWidth, verticalCuts[i + 1] - verticalCuts[i]);
        }        
        
        for(int i = 0; i + 1 < horizontalCuts.size(); ++i){
            int length = horizontalCuts[i + 1] - horizontalCuts[i];
            maxArea = max(maxArea, (long long) length * maxWidth);
        }
        
        return maxArea % mod;
    }
};
