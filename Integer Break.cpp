class Solution {
public:
    int integerBreak(int n) {
        vector <int> dp(n + 1, 1);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                if(i - j >= 1){
                    dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
                }
            }
        }
        return dp[n];
    }
};
