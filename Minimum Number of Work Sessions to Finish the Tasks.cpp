class Solution {
public:
    int solve(int remainingTime, int mask, vector <int> &tasks, int sessionTime, vector <vector <int> > &dp){
        if(mask + 1 == 1 << (int) tasks.size()){
            return 0;
        }
        if(~dp[remainingTime][mask]){
            return dp[remainingTime][mask];
        }
        int cycles = (int) tasks.size();
        bool atleastOne = false;
        for(int i = 0; i < (int) tasks.size(); ++i){
            if((mask & (1 << i)) == 0 and tasks[i] <= remainingTime){
                cycles = min(cycles, solve(remainingTime - tasks[i], (mask | 1 << i), tasks, sessionTime, dp));
                atleastOne = true;
            }
        }
        if(atleastOne == false){
            cycles = min(cycles, 1 + solve(sessionTime, mask, tasks, sessionTime, dp));
        }
        return dp[remainingTime][mask] = cycles;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector <vector <int> > dp(sessionTime + 1, vector <int> (1 << (int) tasks.size(), -1));
        return 1 + solve(sessionTime, 0, tasks, sessionTime, dp);
    }
};
