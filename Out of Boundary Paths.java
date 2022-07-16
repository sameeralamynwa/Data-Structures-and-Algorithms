class Solution {
    static final int mod = 1_000_000_000 + 7;
    static int [] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    
    public int countPaths(int currentRow, int currentColumn, int movesRemaining, int m, int n, int [][][] dp){
        if(currentRow < 0 || currentColumn < 0 || currentRow >= m || currentColumn >= n){
            return 1;
        }
        if(movesRemaining == 0){
            return 0;
        }
        if(dp[currentRow][currentColumn][movesRemaining] != -1){
            return dp[currentRow][currentColumn][movesRemaining];
        }
        int paths = 0;
        for(int d = 0; d < 4; ++d){
            paths += countPaths(currentRow + dx[d], currentColumn + dy[d], movesRemaining - 1, m, n, dp);
            paths %= mod;
        }
        return dp[currentRow][currentColumn][movesRemaining] = paths;
    }
    
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int [][][] dp = new int[m][n][maxMove + 1];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k <= maxMove; ++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        return countPaths(startRow, startColumn, maxMove, m, n, dp);
    }
}
