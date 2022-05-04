class Solution {
public:
    int solve(int pos, int leadingZeros, int n, int mask, vector <vector <vector <int> > > &dp){
        if(pos >= n){
            return 1;
        }
        if(~dp[pos][leadingZeros][mask]){
            return dp[pos][leadingZeros][mask];
        }
        int count = 0;
        if(leadingZeros){
            count += solve(pos + 1, leadingZeros, n, mask, dp);
            for(int d = 1; d <= 9; ++d){
                if((mask & (1 << d)) == 0){
                    count += solve(pos + 1, !leadingZeros, n, mask | 1 << d, dp);
                }
            }
        }
        else{
            for(int d = 0; d <= 9; ++d){
                if((mask & (1 << d)) == 0){
                    count += solve(pos + 1, leadingZeros, n, mask | 1 << d, dp);
                }
            }
        }
        return dp[pos][leadingZeros][mask] = count;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector <vector <vector <int> > > dp(n, vector <vector <int> > (2, vector <int> (1 << 10, -1)));
        return solve(0, 1, n, 0, dp);
    }
};
