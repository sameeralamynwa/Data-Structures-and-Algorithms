class Solution {
public:
    void solve(int pos, vector <int> &nums, vector <int> &currentSequence, vector <vector <int> > &allSequences){
        if(pos == (int) nums.size()){
            if(currentSequence.size() > 1){
                allSequences.push_back(currentSequence);
            }
            return;
        }
        if(currentSequence.empty() or nums[pos] >= currentSequence.back()){
            currentSequence.push_back(nums[pos]);
            int i = 0, j = 0;
            for(; j < nums.size(); ++j){
                if(nums[j] == currentSequence[i]){
                    ++i;
                }
                if(i == (int) currentSequence.size()){
                    break;
                }
            }
            if(j == pos){
                solve(pos + 1, nums, currentSequence, allSequences);
            }
            currentSequence.pop_back();
        }
        solve(pos + 1, nums, currentSequence, allSequences);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <vector <int> > allSequences;
        vector <int> currentSequence;
        solve(0, nums, currentSequence, allSequences);
        return allSequences;
    }
};
