class Solution {
    static final int mod = 1_000_000_007;
    
    public int computeWays(int n, int target, int k, int [][] dp){
        if(target == 0){
            return n == 0 ? 1 : 0;
        }
        
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        int ways = 0;
        for(int possibleFaceValue = 1; possibleFaceValue <= k; ++possibleFaceValue){
            if(target - possibleFaceValue >= 0 && n > 0){
                ways += computeWays(n - 1, target - possibleFaceValue, k, dp);
                ways %= mod;
            }
        }
        
        return dp[n][target] = ways;
    }
    
    public int numRollsToTarget(int n, int k, int target) {
        int [][] dp = new int[n + 1][target + 1];
        for(int i = 0; i <= n; ++i){
            for(int sum = 0; sum <= target; ++sum){
                dp[i][sum] = -1;
            }
        }
        return computeWays(n, target, k, dp);
    }
}
