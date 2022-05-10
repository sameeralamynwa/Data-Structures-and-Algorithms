class Solution {
public:
    void solve(int taken, int sumLeft, vector <int> soFar, vector <vector <int> > &allCombinations){
        if(taken == 0 and sumLeft == 0){
            if(sumLeft == 0){
                allCombinations.push_back(soFar);
            }
            return;
        }
        for(int maybe = soFar.empty() ? 1 : soFar.back() + 1; maybe <= min(9, sumLeft); maybe++){
            if(taken > 0 and find(soFar.begin(), soFar.end(), maybe) == soFar.end()){
                soFar.push_back(maybe);
                solve(taken - 1, sumLeft - maybe, soFar, allCombinations);
                soFar.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector <int> > allCombinations;
        solve(k, n, {}, allCombinations);
        return allCombinations;
    }
};
