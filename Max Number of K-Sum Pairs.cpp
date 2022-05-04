class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, maxPairs = 0;
        while(l < n){
            while(r > l and nums[l] + nums[r] > k){
                --r;
            }
            if(r > l and nums[l] + nums[r] == k){
                maxPairs++;
                --r;
            }
            ++l;
        }
        return maxPairs;
    }
};
