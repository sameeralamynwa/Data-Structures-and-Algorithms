class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sum = 0, maxOnes = 0, l = 0, r = 0;
        while(l < (int) nums.size()){
            while(r < (int) nums.size() and sum <= k){
                sum += nums[r] == 0;
                ++r;
            }
            if(sum > k){
                maxOnes = max(maxOnes, r - l - 1);
            }
            else{
                maxOnes = max(maxOnes, r - l);
            }
            sum -= nums[l] == 0;
            ++l;
        }
        return maxOnes;
    }
};
