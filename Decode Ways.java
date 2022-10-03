class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int [] dp = new int[n];
        for(int i = 0; i < n; ++i){
            int digit = (int) s.charAt(i) - (int) '0';
            if(digit > 0){
                if(i - 1 >= 0){
                    dp[i] = dp[i - 1];
                }
                else{
                    dp[i] = 1;
                }
            }
            if(i > 0){
                int previousDigit = (int) s.charAt(i - 1) - (int) '0';
                if(previousDigit * 10 + digit >= 10 && previousDigit * 10 + digit <= 26){
                    if(i - 2 >= 0){
                        dp[i] += dp[i - 2];
                    }
                    else{
                        dp[i] += 1;
                    }
                }
            }
        }
        return dp[n - 1];
    }
}
