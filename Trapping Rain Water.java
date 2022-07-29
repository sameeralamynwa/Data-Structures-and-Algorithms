class Solution {
    public static int max(int a, int b){
        return a > b ? a : b;
    }
    
    public int trap(int[] height) {
        int n = height.length, trappedWater = 0;
        for(int i = 0; i < n; ){
            int j = i + 1;
            while(j < n && height[j] < height[i]){
                ++j;
            }
            if(j < n){
                for(int k = i + 1; k < j; ++k){
                    trappedWater += height[i] - height[k];
                }
            }
            else{
                int maxBar = 0;
                for(int k = n - 1; k > i; --k){
                    trappedWater += max(0, maxBar - height[k]);
                    maxBar = max(maxBar, height[k]);
                }
            }
            i = j;
        }
        return trappedWater;
    }
}
