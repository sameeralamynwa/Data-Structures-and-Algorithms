class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minSubsequences = 0;
        for(int i = 0; i < (int) nums.size(); ){
            int j = i;
            while(nums[j] - nums[i] <= k and ++j < (int) nums.size());
            i = j;
            minSubsequences++;
        }
        return minSubsequences;
    }
};
