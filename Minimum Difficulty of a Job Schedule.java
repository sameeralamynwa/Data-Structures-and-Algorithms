class Solution {
    public void preFill(int [][] dp, int d, int n){
        for(int i = 0; i < d; ++i){
            for(int j = 0; j < n; ++j){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
    }
    
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        int [][] dp = new int[d][n];
        preFill(dp, d, n);
        for(int days = 0; days < d; ++days){
            if(days == 0){
                for(int task = 0; task < n; ++task){
                    dp[days][task] = jobDifficulty[task];
                    if(task > 0){
                        dp[days][task] = Math.max(dp[days][task], dp[days][task - 1]);
                    }
                }
            }
            else{
                for(int task = days; task < n; ++task){
                    int maxDifficulty = 0;
                    for(int from = task; from >= days; --from){
                        maxDifficulty = Math.max(maxDifficulty, jobDifficulty[from]);
                        dp[days][task] = Math.min(dp[days][task], maxDifficulty + dp[days - 1][from - 1]);
                    }
                }
            }
        }
        return dp[d - 1][n - 1] == Integer.MAX_VALUE ? -1 : dp[d - 1][n - 1];
    }
}
