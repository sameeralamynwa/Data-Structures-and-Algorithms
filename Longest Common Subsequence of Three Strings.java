class Solution {
    public int solve(String a, String b, String c) {
        if(a == "" || b == "" || c == ""){
            return 0;
        }
        
        int [][][] dp = new int[a.length()][b.length()][c.length()];
        for(int i = 0; i < a.length(); ++i){
            for(int j = 0; j < b.length(); ++j){
                for(int k = 0; k < c.length(); ++k){
                    if(a.charAt(i) == b.charAt(j) && b.charAt(j) == c.charAt(k)){
                        if(i > 0 && j > 0 && k > 0){
                            dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                        }
                        else{
                            dp[i][j][k] = 1;
                        }
                    }
                    else{
                        if(i > 0){
                            dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j][k]);
                        }
                        if(j > 0){
                            dp[i][j][k] = Math.max(dp[i][j][k], dp[i][j - 1][k]);
                        }
                        if(k > 0){
                            dp[i][j][k] = Math.max(dp[i][j][k], dp[i][j][k - 1]);
                        }
                    }
                }
            }
        }
        
        return dp[a.length() - 1][b.length() - 1][c.length() - 1];
    }
}
