class Solution {
public:
    int solve(int pos, vector <int> &a, vector <int> &dp){
        if(pos >= (int) a.size() - 1){
            return 0;
        }
        if(~dp[pos]){
            return dp[pos];
        }
        int minJumps = (int) a.size();
        for(int jumpStep = 1; jumpStep <= a[pos]; jumpStep++){
            int considerThisJump = 1 + solve(pos + jumpStep, a, dp);
            minJumps = min(minJumps, considerThisJump);
        }
        return dp[pos] = minJumps;
    }
    int jump(vector<int> &a) {
        vector <int> dp((int) a.size(), -1);
        return solve(0, a, dp);
    }
};
