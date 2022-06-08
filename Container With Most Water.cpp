class Solution {
public:
    int searchMaximum(int low, int high, int target, vector <int> &suffixMaximum){
        if(low >= high){
            return low;
        }
        int mid = (low + high + 1) >> 1;
        if(suffixMaximum[mid] >= target){
            return searchMaximum(mid, high, target, suffixMaximum);
        }
        else{
            return searchMaximum(low, mid - 1, target, suffixMaximum);
        }
    }
    
    int solve(vector <int> &height){
        int n = (int) height.size(), maxWater = 0;
        vector <int> suffixMaximum(n);
        for(int i = n - 1; i >= 0; --i){
            if(i == n - 1){
                suffixMaximum[i] = height[i];
            }
            else{
                suffixMaximum[i] = max(suffixMaximum[i + 1], height[i]);
            }
        }
        for(int i = 0; i < n; ++i){
            int justGreaterIndex = searchMaximum(i, n - 1, height[i], suffixMaximum);
            maxWater = max(maxWater, (justGreaterIndex - i) * height[i]);
        }
        return maxWater;
    }
    
    int maxArea(vector<int>& height) {
        int maxWater = solve(height);
        reverse(height.begin(), height.end());
        return max(maxWater, solve(height));
    }
};
