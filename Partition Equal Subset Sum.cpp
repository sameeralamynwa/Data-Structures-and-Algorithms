class Solution {
public:
    bool solve(int pos, int n, vector <int> &nums, int remainingSum, vector <vector <int> > &dp){
        if(pos == n){
            return remainingSum == 0;
        }
        
        if(remainingSum < 0){
            return false;
        }
        
        if(dp[pos][remainingSum] != -1){
            return dp[pos][remainingSum];
        }
        
        return dp[pos][remainingSum] = solve(pos + 1, n, nums, remainingSum, dp) or solve(pos + 1, n, nums, remainingSum - nums[pos], dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = (int) nums.size(), sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }
        
        vector <vector <int> > dp(n, vector <int> (sum / 2 + 1, -1));
        
        return sum % 2 == 0 and solve(0, n, nums, sum >> 1, dp);
    }
};
