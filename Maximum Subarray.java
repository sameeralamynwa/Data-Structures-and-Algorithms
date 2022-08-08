class Solution {
    public int max(int x, int y){
        return x > y ? x : y;
    }
    
    public int maxSubArray(int[] nums) {
        int currentSum = 0, maxSum = Integer.MIN_VALUE;
        for(int x : nums){
            currentSum = max(x, currentSum + x);
            maxSum = max(maxSum, currentSum);
            currentSum = max(currentSum, 0);
        }
        return maxSum;
    }
}
