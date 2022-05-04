class Solution {
public:
    int solve(int pos, int currentOR, int maxBitwiseOR, vector <int> &nums){
        if(pos == (int) nums.size()){
            return currentOR == maxBitwiseOR;
        }
        return solve(pos + 1, currentOR | nums[pos], maxBitwiseOR, nums) + solve(pos + 1, currentOR, maxBitwiseOR, nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitwiseOR = 0;
        for(int i = 0; i < 20; ++i){
            for(int x : nums){
                if((x & (1 << i))){
                    maxBitwiseOR |= 1 << i;
                }
            }
        }
        return solve(0, 0, maxBitwiseOR, nums);
    }
};

