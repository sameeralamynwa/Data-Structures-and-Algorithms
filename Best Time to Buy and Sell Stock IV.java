class Solution {
    final int totalStates = 2, buyState = 0, sellState = 1;
    
    public int maxProfit(int k, int[] prices) {
        if(prices.length == 0 || k == 0){
            return 0;
        }
        
        int[][][] dp = new int[prices.length][k][totalStates];
        
        for(int transaction = 0; transaction < k; ++transaction){
            for(int pos = 0; pos < prices.length; ++pos){
                if(transaction == 0){
                    if(pos == 0){
                        dp[pos][transaction][buyState] = -prices[pos];
                    }
                    else{
                        dp[pos][transaction][buyState] = -prices[pos];
                        dp[pos][transaction][buyState] = Math.max(dp[pos][transaction][buyState], dp[pos - 1][transaction][buyState]);
                        
                        dp[pos][transaction][sellState] = prices[pos] + dp[pos - 1][transaction][buyState];
                        dp[pos][transaction][sellState] = Math.max(dp[pos][transaction][sellState], dp[pos - 1][transaction][sellState]);
                    }
                }
                else{
                    if(pos == 0){
                        dp[pos][transaction][buyState] = dp[pos][transaction - 1][buyState];
                        dp[pos][transaction][sellState] = dp[pos][transaction - 1][sellState];
                    }
                    else{
                        dp[pos][transaction][buyState] = -prices[pos] + dp[pos - 1][transaction - 1][sellState];
                        dp[pos][transaction][buyState] = Math.max(dp[pos][transaction][buyState], dp[pos - 1][transaction][buyState]);
                        dp[pos][transaction][buyState] = Math.max(dp[pos][transaction][buyState], dp[pos][transaction - 1][buyState]);
                        
                        dp[pos][transaction][sellState] = prices[pos] + dp[pos - 1][transaction][buyState];
                        dp[pos][transaction][sellState] = Math.max(dp[pos][transaction][sellState], dp[pos - 1][transaction][sellState]);
                        dp[pos][transaction][sellState] = Math.max(dp[pos][transaction][sellState], dp[pos][transaction - 1][sellState]);
                    }
                }
            }
        }
        return dp[prices.length - 1][k - 1][sellState];
    }
}
