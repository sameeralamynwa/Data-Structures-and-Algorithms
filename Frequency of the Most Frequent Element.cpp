class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = (int) nums.size() - 1, r = (int) nums.size() - 1, maxFreq = 0, n = (int) nums.size();
        long long operations = 0;
        while(r >= 0){
            while(l >= 0 and operations + nums[r] - nums[l] <= k){
                operations += nums[r] - nums[l];
                --l;
            }
            if(l >= 0){
                maxFreq = max(maxFreq, r - l);
                operations -= (long long) nums[r] * max(0, r - l - 1);
                if(r - 1 >= 0){
                    operations += (long long) nums[r - 1] * max(0, r - l - 1);
                }
            }
            else{
                maxFreq = max(maxFreq, r + 1);
                operations -= (long long) nums[r] * r;
                if(r - 1 >= 0){
                    operations += (long long) nums[r - 1] * max(0, r - 1);
                }
            }
            --r;
        }
        return maxFreq;
    }
};
